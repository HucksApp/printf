#include "main.h"
/**
* _printf - function that prints to standard output
* according to specified format
* @format: format (char, string, int, decimal)
* @...: arrays of variable
* Return: size the output text;
*/
int _printf(const char *format, ...)
{
	int iter, width, size, precision, buffer_index = 0;
	int  len = 0, prints = 0;
	int flags;
	va_list ap;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	iter = 0;
	while (format && format[iter] != '\0')
	{
		switch (format[iter])
		{
		case FMT_SYB:
			_print_chars(buffer, &buffer_index);
			flags = _get_flags(format, &iter);
			width = _get_width(format, &iter, ap);
			precision = _get_precision(format, &iter, ap);
			size = _get_size(format, &iter);
			iter++;
			prints = _print_formater(format, &iter, ap, buffer, flags,
								width, precision, size);
			if (prints == -1)
				return (-1);
			len += prints;
			break;
		default:
			buffer[buffer_index++] = format[iter];
			if (buffer_index == BUFFER_SIZE)
			_print_chars(buffer, &buffer_index);
			len++;
			break;
		}
		iter++;
	}
	_print_chars(buffer, &buffer_index);
	va_end(ap);
	return (len);
}
