#include "main.h"

/**
 * _print_non_printable - prints ascii value of non printable chars
 * @ap: List of args
 * @buffer: Buffer array of formated strings
 * @flag:  passed flags
 * @precision: precision
 * @width: width
 * @size: size specifier
 * Return: printer counter
 */
int _print_non_printable(va_list ap, char buffer[],
				int flag, int width, int precision, int size)
{
	int offset = 0, index = 0;
	char *str = va_arg(ap, char *);

	UNUSED_VAR(flag);
	UNUSED_VAR(width);
	UNUSED_VAR(precision);
	UNUSED_VAR(size);

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[index] != '\0')
	{
		if (_is_printable_char(str[index]))
			buffer[index + offset] = str[index];
		else
			offset += _append_hexa(str[index], buffer, index + offset);
		index++;
	}
	buffer[index + offset] = '\0';
	return (write(1, buffer, index + offset));
}

