#include "main.h"






/**
 * _print_binary - rints binary number
 * @buffer: Buffer array of formated strings
 * @ap: list
 * @flag:  passed flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: printer counter
 */
int _print_binary(va_list ap, char buffer[],
	int flag, int width, int precision, int size)
{
	unsigned int n, m, sum, a[32];
	int count, iter;

	UNUSED_VAR(buffer);
	UNUSED_VAR(flag);
	UNUSED_VAR(width);
	UNUSED_VAR(precision);
	UNUSED_VAR(size);

	n = va_arg(ap, unsigned int);
	m = 2147483648;
	a[0] = n / m;

	iter = 1;
	while (iter < 32)
	{
		m /= 2;
		a[iter] = (n / m) % 2;
		iter++;
	}

	for (iter = 0, sum = 0, count = 0; iter < 32; iter++)
	{
		sum += a[iter];
		if (sum || iter == 31)
		{
			char rs = ATI_ORIGIN + a[iter];

			_putchar(rs);
			count++;
		}
	}
	return (count);
}

