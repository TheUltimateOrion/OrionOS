#include <orion/drivers/vga.h>
#include <orion/arch/x86.h>

extern struct screen_t* screen;

static void __cursor_update(void);

void vga_cursor_toggle(void) {
	outb(CRTC_ADDR_REG, 0x0A);
	uint8_t prev = inb(CRTC_DATA_REG);
	outb(CRTC_ADDR_REG, 0x0A);
	outb(CRTC_DATA_REG, prev ^ (0x1 << 5));
}

void vga_textmode_setcursor(uint8_t x, uint8_t y) {
    screen->cur.x = x;
    screen->cur.y = y;
    __cursor_update();
}

void vga_textmode_getcursor(uint8_t* x, uint8_t* y) {
    *x = screen->cur.x;
    *y = screen->cur.y;
}

static void __cursor_update(void) {
    uint16_t pos = (uint16_t)(screen->cur.y * VGA_WIDTH) + screen->cur.x;
    outb(CRTC_ADDR_REG, CURSOR_LOWPTR);
    outb(CRTC_DATA_REG, (uint8_t)(pos & 0xFF));
    outb(CRTC_ADDR_REG, CURSOR_HIGHPTR);
    outb(CRTC_DATA_REG, (uint8_t)((pos >> 8) & 0xFF));
}