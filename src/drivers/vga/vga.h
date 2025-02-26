#ifndef __VGA_H
#define __VGA_H
#include <libc/stdlib.h>

#define VGA_DEFINEx(func, ...) void FASTCALL vga_##func(__VA_ARGS__)
#define VGA_DEFINE0(func) VGA_DEFINEx(func, void)
#define VGA_DEFINE1(func, _A) void FASTCALL vga_##func(_A);
#define VGA_DEFINE2(func, _A, _B) void FASTCALL vga_##func(_B)

#endif // __VGA_H