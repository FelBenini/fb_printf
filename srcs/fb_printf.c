#include "../includes/fb_printf.h"

void    fb_putchar(char c)
{
        write(1, &c, 1);
}

void fb_putnbr(int nb)
{
	long int num;

	num = nb;
    if (num < 0) {
    	fb_putchar('-');
        num = num * -1;
    }
    if (num >= 0 && num <= 9) {
		fb_putchar(num + '0');
    }
	if (num > 9) {
		fb_putnbr(num / 10);
		fb_putnbr(num % 10);
	}
}

int fb_printf(char *str, ...)
{
	int i = 0;
	va_list args;
	va_start(args, str);

	while (str[i])
	{
		if (str[i] == '%') {
			fb_putnbr(va_arg(args, int));
			i += 2;
		} else
			fb_putchar(str[i++]);
	}
	va_end(args);
	return (i);
}
