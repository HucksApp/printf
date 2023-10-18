#include "main.h"


/**
 *  _print_rev - prints string in reverse
 * @rv: number to convert
 * Return: printer counter (int)
 *
*/


int _print_rev(va_list rv)
{
	int i, count = 0;
	char *s_ptr;

	s_ptr = va_arg(rv, char*);
	if (s_ptr == NULL)
		s_ptr = ")llun(";
	i = 0;
	while (s_ptr[i] != '\0')
	for (i -= 1; i >= 0; i--)
	{
		_putchar(s_ptr[i]);
		count++;

	}
	return (count);
}

