#include "main.h"

/**
 * _print_dtstring - print control char .
 * @str: argumen t.
 * Return: the length of the string.
 */

int _print_dtstring(va_list str)
{
	int ascii_v, selector = 1, string_count = 0;
	char *char_string;

	char_string = va_arg(str, char*);

	while (*char_string != '\0')
	{
	ascii_v = (int) (*char_string);
	if (ascii_v < 32 || ascii_v >= 127)
	{
		_putchar('\\');
		_putchar('x');

		if (ascii_v < 16)
		_putchar('0');
		string_count += 2;
		string_count +=  _print_hex(ascii_v, selector);
		char_string += 1;
	}

		_putchar(*char_string);
		string_count++;
		char_string++;
	}

	(void) char_string;
	return (string_count);
}


