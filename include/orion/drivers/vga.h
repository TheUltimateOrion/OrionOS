#ifndef __VGA_H
#define __VGA_H

#include <orion/types.h>
#include <orion/arch/x86.h>

#define VGA_DEFINEx(func, ...) void FASTCALL vga_##func(__VA_ARGS__)
#define VGA_DEFINE0(func) VGA_DEFINEx(func, void)
#define VGA_DEFINE1(func, _A) void FASTCALL vga_##func(_A)
#define VGA_DEFINE2(func, _A, _B) void FASTCALL vga_##func(_A, _B)

#define VGA_WIDTH (uint16_t)80
#define VGA_HEIGHT (uint16_t)25
#define VGA_BASEADDR 0xB8000
#define CRTC_ADDR_REG 0x3D4
#define CRTC_DATA_REG 0x3D5
#define CURSOR_HIGHPTR 0x0E
#define CURSOR_LOWPTR 0x0F


struct cursor_t {
    uint8_t x;
    uint8_t y;
};

struct screen_t {
    struct cursor_t cur;
    volatile uint16_t* vga_buffer;
    uint8_t text_color;
};

typedef enum {
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHT_GREY = 7,
    DARK_GREY = 8,
    LIGHT_BLUE = 9,
    LIGHT_GREEN = 10,
    LIGHT_CYAN = 11,
    LIGHT_RED = 12,
    LIGHT_MAGENTA = 13,
    YELLOW = 14,
    WHITE = 15
} __attribute__((packed)) vga_color_t;

void vga_cursor_toggle(void);
VGA_DEFINE0(console_init); // void vga_console_init(void);
VGA_DEFINE0(console_clear);
VGA_DEFINE2(console_setcolor, vga_color_t, vga_color_t); // void vga_console_setcolor(vga_color_t, vga_color_t);
VGA_DEFINE2(console_setcursor, uint8_t, uint8_t); // void vga_console_setcursor(uint8_t, uint8_t);
VGA_DEFINE2(console_getcursor, uint8_t*, uint8_t*); //void vga_console_getcursor(uint8_t*, uint8_t*);
VGA_DEFINE1(console_putchar, char); //void vga_console_putchar(char);
VGA_DEFINE1(console_write, const char*); //void vga_console_puts(const char*);

#endif // __VGA_H