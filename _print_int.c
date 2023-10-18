#include "main.h"



/**
 *_putint - print integer helper
 * function
 * @n: integer to be printed
 * @count: printer counter
 *
*/


void _putint(long n, int *count)
{
	if (n < 0)
	{
	_putchar('-');
	(*count)++;
	n = -n;
	}
	if (n / 10)
		_putint(n / 10, count);
	_putchar(n % 10 + '0');
	(*count)++;
}



/**
 * _print_int - print integer
 * function
 * @i: integers to be printed
 *
 * Return: printer counter (int)
*/

int _print_int(va_list i)
{
	int next_var, count = 0;

	next_var = va_arg(i, int);
	_putint(next_var, &count);

	return (count);
}

