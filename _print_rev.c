#include "main.h"


/**
 *  _print_rev - prints string in reverse
 * @rv: number to convert
 * Return: printer counter (int)
 *
*/


int _print_rev(va_list rv)
{
	int i, j = 0, count = 0;
	char *s_ptr;

	s_ptr = va_arg(rv, char*);
	if (s_ptr == NULL)
		s_ptr = "(null)";
	i = 0;
	while (s_ptr[i] != '\0')
		i++;
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(s_ptr[j]);
		count++;

	}
	return (count);
}

