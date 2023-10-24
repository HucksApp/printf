#include "main.h"
/**
*  _print_formater - Prints type formated chars
* @fmt: Formatted string in which to print the arguments
* @ap:  args
* @precision: Precision
* @index: index
* @flags: passed flags
* @buffer:  Array of formated string
* @width: width
* @size: Size specifier
* Return: 1 or 2
*/
int _print_formater(const char *fmt, int *index, va_list ap, char buffer[],
	int flags, int width, int precision, int size)
{
	int iter, len = 0, printed = -1;
	print_format fmt_fn[] = {
	{'c', _print_char}, {'s', _print_string},
	{'%', _print_percentage}, {'i', _print_int},
	{'d', _print_int}, {'b', _print_binary},
	{'u', _print_unsigned}, {'o', _print_octal},
	{'x', _print_hexa_x}, {'X', _print_hexa_X},
	{'p', _print_pointer}, {'S', _print_non_printable},
	{'r', _print_reverse}, {'R', _print_rot13},
	{'\0', NULL}
	};
	iter = 0;
	while (fmt_fn[iter].fmt != '\0')
	{
		if (fmt[*index] == fmt_fn[iter].fmt)
			return (fmt_fn[iter].fn(ap, buffer, flags, width, precision, size));
		iter++;
	}
	if (fmt_fn[iter].fmt == '\0')
	{
	if (fmt[*index] == '\0')
		return (-1);
	len += _putchar('%');
	if (fmt[*index - 1] == ' ')
		len += _putchar(' ');
	else if (width)
	{
		--(*index);
		while (fmt[*index] != ' ' && fmt[*index] != FMT_SYB)
		--(*index);
		if (fmt[*index] == ' ')
			--(*index);
		return (1);
	}
	len += _putchar(fmt[*index]);
		return (len);
	}
	return (printed);
}

