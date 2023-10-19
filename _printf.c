#include "main.h"



/**
  * find_function - function that finds formats for _printf
  * calls the corresponding function.
  * @format: format (char, string, int, decimal)
  * Return: NULL or function associated ;
  */
int (*find_function(const char *format))(va_list)
{
	unsigned int iter = 0;
	print_format find_fn[] = {
		{"c", _print_char},
		{"s", _print_string},
		{"i", _print_int},
		{"d", _print_int},
		{"r", _print_rev},
		{"b", _print_bin},
		{"u", _print_unsig},
		{"o", _print_oct},
		{"%%", _print_percentage},
		{"x", _print_hexx},
		{"X", _print_hexX},
		{"R", _print_rot13},
		{NULL, NULL}
	};

	while (find_fn[iter].spc)
	{
		if (find_fn[iter].spc[0] == (*format))
			return (find_fn[iter].fn);
		iter++;
	}
	return (NULL);
}

/**
 * record - print record helper
 * @a: variable member a
 * @av: variable member a value
 * @b: variable member b
 * @bv: variable member b value
 *
*/


void record(int *a, int av, int *b, int bv)
{

	*a += av;
	*b += bv;
}



/**
  * _printf - function that produces output according to a format.
  * @format: format (char, string, int, decimal)
  * Return: size the output text;
  */

int _printf(const char * const format, ...)
{
	va_list ap;
	int (*f)(va_list), iter = 0, len = 0;

	va_start(ap, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
start:
	while (format[iter] != '\0')
	{
		while (format[iter] != FMT_SYB && format[iter])
		{
			_putchar(format[iter]);
			iter++;
			len++;
			goto start;
		}
		while (format[iter] == FMT_SYB && format[iter])
		{
			f = find_function(&(format[iter + 1]));
			if (f != NULL)
				record(&iter, 2, &len, f(ap));
			else if (f == NULL && format[iter + 1] == ' '
					&& format[iter + 2] == FMT_SYB)
			{
				_putchar(FMT_SYB);
				record(&iter, 3, &len, 1);
			}
			else
			{
				_putchar(format[iter]);
				 record(&iter, 1, &len, 1);
			}
		}
		if (format[iter] != '\0' && format[iter])
			goto start;
	}
	return (len);
}

