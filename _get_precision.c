#include "main.h"

/**
* _get_precision -  precision for printing
* @format: Formatted string
* @n: index
* @ap: list of arguments
*
* Return: Precision.
*/
int _get_precision(const char *format, int *n, va_list ap)
{
	int current_index = *n + 1, precision = 0;

	if (format[current_index] != '.')
		return (-1);

	current_index += 1;
	while	(format[current_index] != '\0')
	{
		if (isdigit(format[current_index]))
		{
			precision *= 10;
			precision += format[current_index] - ATI_ORIGIN;
		}
		else if (format[current_index] == '*')
		{
		current_index++;
		precision = va_arg(ap, int);
		break;
		}
		else
			break;
		current_index++;
	}
		*n = current_index - 1;
		return (precision);
}

