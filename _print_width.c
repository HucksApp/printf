#include "main.h"





/**
* _get_width - Calculates the width for printing
* @format: Formatted string in which to print the arguments
* @n: List of arguments to be printed
* @list: list of arguments
*
* Return: width.
*/
int _get_width(const char *format, int *n, va_list list)
{
	int current_index, width = 0;

	current_index = *n + 1;
	while (format[current_index] != '\0')
	{
		if (_is_digit(format[current_index]))
		{
			width *= 10;
			width += format[current_index] - ATI_ORIGIN;
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
		current_index++;
	}
		*n = current_index - 1;
		return (width);
}

