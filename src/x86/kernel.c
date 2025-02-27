
#include <orion/drivers/vga.h>

void kmain(void);

void kmain(void)
{
    vga_textmode_init();
    vga_textmode_clear();
    char str[3];
    for (int16_t i = -5; i <= 5; i++)
    {
        itoa(i, str);
        vga_textmode_puts(str);
        vga_textmode_putchar('\n');
    }

	return;
}