#include <orion/drivers/vga.h>
#include <orion/print.h>
#include <orion/arch/x86.h>
#include <orion/arch/multiboot.h>

void kmain(uint64_t magic, unsigned long addr);

void kmain (uint64_t magic, unsigned long addr)
{
    vga_console_init();
    vga_console_clear();
    register_console(&vga_console_putchar);
    printf("Hello, World!\n");
	return;
}