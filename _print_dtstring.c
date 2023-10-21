#include "main.h"

/**
 * _print_dtstring2 - print control char .
 * @str: argumen t.
 * Return: the length of the string.
 */

int _print_dtstring3(va_list str)
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




/**
 * _print_dtstring - print exclusuives string.
 * @val: argumen t.
 * Return: the length of the string.
 */
int _print_dtstring(va_list val)
{
	int i = 0, offset = 0;
	char *str = va_arg(val, char *);
	char buffer[10];

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}


