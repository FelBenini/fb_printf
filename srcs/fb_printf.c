#include "../includes/fb_printf.h"

int fb_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int fb_putnbr(int nb)
{
	long int num;
	static int len = 0;

	num = nb;
    if (num < 0) {
    	fb_putchar('-');
        num = num * -1;
    }
    if (num >= 0 && num <= 9) {
		fb_putchar(num + '0');
		len += 1;
    }
	if (num > 9) {
		fb_putnbr(num / 10);
		fb_putnbr(num % 10);
	}
	return (len);
}

int fb_putunsigned(unsigned int nb)
{
	int len = 0;

    if (nb <= 9) {
		fb_putchar(nb + '0');
		len += 1;
    }
	if (nb > 9) {
		fb_putunsigned(nb / 10);
		fb_putunsigned(nb % 10);
	}
	return (len);
}

int fb_putstr(char *str)
{
	int i = 0;

	while (str[i])
		fb_putchar(str[i++]);
	return (i);
}

void print_formats(char c, va_list args, int *printed_chars)
{
	if (c == 'd' || c == 'i')
		*printed_chars += fb_putnbr(va_arg(args, int));
	if (c == 'u')
		*printed_chars += fb_putunsigned(va_arg(args, unsigned int));
	if (c == 'c')
		*printed_chars += fb_putchar(va_arg(args, int));
	if (c == 's')
		*printed_chars += fb_putstr(va_arg(args, char *));
	if (c == '%')
		*printed_chars += fb_putchar('%');
}

int fb_printf(char *str, ...)
{
	int i = 0;
	va_list args;
	va_start(args, str);
	int printed_chars = 0;

	while (str[i])
	{
		if (str[i] == '%') {
			print_formats(str[i + 1], args, &printed_chars);
			i += 2;
		} else
			printed_chars += fb_putchar(str[i++]);
	}
	va_end(args);
	return (printed_chars);
}
