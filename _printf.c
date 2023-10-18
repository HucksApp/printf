#include "main.h"

/**
  * find_function - function that finds formats for _printf
  * calls the corresponding function.
  * @format: format (char, string, int, decimal)
  * Return: NULL or function associated ;
  */
int (*find_function(const char *format))(va_list)
{
	unsigned int i = 0;
	prt_fmt find_f[] = {
		{"c", _print_char},
		{"s", _print_string},
		{"i", _print_int},
		{"d", _print_int},
		{"r", _print_rev},
		{"b", _print_bin},
		{"u", _print_unsig},
		{"o", _print_oct},
		{"x", _print_hexx},
		{"X", _print_hexX},
		{"R", _print_rot13},
		{NULL, NULL}
	};

	while (find_f[i].spc)
	{
		if (find_f[i].spc[0] == (*format))
			return (find_f[i].fn);
		i++;
	}
	return (NULL);
}
/**
  * _printf - function that produces output according to a format.
  * @format: format (char, string, int, decimal)
  * Return: size the output text;
  */
int _printf(const char *format, ...)
{
	va_list ap;
	int (*f)(va_list);
	unsigned int i = 0, cprint = 0;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			cprint++;
			i++;
		}
		if (format[i] == '\0')
			return (cprint);
		f = find_function(&format[i + 1]);
		if (f != NULL)
		{
			cprint += f(ap);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		cprint++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(ap);
	return (cprint);
}
