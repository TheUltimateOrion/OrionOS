#include <orion/drivers/vga.h>

struct screen_t* screen;

static void __newline(void);
static uint16_t __vga_char(char, uint8_t);
static void __cursor_update(void);

// void vga_textmode_init(void) {

VGA_DEFINE0(textmode_init) { 
    screen->vga_buffer = (uint16_t*) VGA_BASEADDR;
	screen->cur.x = 0;
	screen->cur.y = 0;
	screen->text_color = (LIGHT_GREY | (BLACK << 4));
	vga_textmode_clear();
}

VGA_DEFINE0(textmode_clear) {
	vga_textmode_setcolor(LIGHT_GREY, BLACK);
    for (uint16_t i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        screen->vga_buffer[i] = __vga_char(' ', screen->text_color);
    }
    screen->cur.x = 0;
    screen->cur.y = 0;
    __cursor_update();
}

void vga_textmode_setcolor(vga_color_t fg, vga_color_t bg) {
    screen->text_color = fg | (bg << 4);
}

void vga_textmode_putchar(char c) {
	if(c == '\n') {
		__newline();
	} else {
		screen->vga_buffer[screen->cur.y * VGA_WIDTH + screen->cur.x] = __vga_char(c, screen->text_color);
		if (++screen->cur.x >= VGA_WIDTH) {
			__newline();
		}
	}
    __cursor_update();
}

void vga_textmode_puts(const char* str) {
    while(*str != '\0') {
		vga_textmode_putchar(*str++);
	}
}

static uint16_t __vga_char(char c, uint8_t color) {
	return (uint16_t)(c | (color << 8));
}

static void __cursor_update(void) {
    uint16_t pos = (uint16_t)(screen->cur.y * VGA_WIDTH) + screen->cur.x;
    outb(CRTC_ADDR_REG, CURSOR_LOWPTR);
    outb(CRTC_DATA_REG, (uint8_t)(pos & 0xFF));
    outb(CRTC_ADDR_REG, CURSOR_HIGHPTR);
    outb(CRTC_DATA_REG, (uint8_t)((pos >> 8) & 0xFF));
}


static void __newline(void) {
    screen->cur.x = 0;
    if (++screen->cur.y >= VGA_HEIGHT) {
        // Scroll screen up
        for (uint16_t i = 0; i < (VGA_HEIGHT - 1) * VGA_WIDTH; i++) {
            screen->vga_buffer[i] = screen->vga_buffer[i + VGA_WIDTH];
        }
        // Clear last line
        for (uint16_t i = (VGA_HEIGHT - 1) * VGA_WIDTH; i < VGA_HEIGHT * VGA_WIDTH; i++) {
            screen->vga_buffer[i] = __vga_char(' ', screen->text_color);
        }
        screen->cur.y = VGA_HEIGHT - 1;
    }
}