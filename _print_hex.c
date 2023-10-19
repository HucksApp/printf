#include "main.h"


/**
 * _print_hex - print hex value
 * @selector: format selector
 * @hx: value to be converted
 * Return: printer counter (int)
*/

int _print_hex(unsigned int hx, unsigned int selector)
{
unsigned int power16, count_n, hex_n, nm, i;
char base;
int count = 0;

	if (hx != 0)
	{
		count_n = 0;
		nm = hx;
		if (selector)
		base = 'A' - ':';
		else
			base = 'a' - ':';
		while (nm != 0)
		{
			nm /= 16;
			count_n++;
		}
		power16 = 1;
		for (i = 1; i <= count_n - 1; i++)
			power16 *= 16;
		i = 1;
		while (i <= count_n)
		{
			hex_n = hx / power16;
			if (hex_n < 10)
				_putchar(hex_n + '0');
			else
				_putchar(hex_n + '0' + base);
			count++;
			hx -= hex_n * power16;
			power16 /= 16;
			i++;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}



/**
 *  _print_hexx - Print hex value
 * @h: value to be converted
 * Return: printer counter (int)
*/

int _print_hexx(va_list h)
{
	return (_print_hex(va_arg(h, unsigned int), 0));
}





/**
 *  _print_hexX - Print hex value
 * @h: value to be converted
 * Return: printer counter (int)
*/

int _print_hexX(va_list h)
{
	return (_print_hex(va_arg(h, unsigned int), 1));
}

