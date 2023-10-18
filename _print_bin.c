#include "main.h"

/**
* _print_bin - convert number to binary
* @b: number to print
* Return: printer counter (int)
*/

int _print_bin(va_list b)
{
	int count = 0;
	unsigned int len, pow2, j, digit, n, num;

	n = va_arg(b, unsigned int);
	if (n != 0)
	{
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 2;
			len++;
		}
		pow2 = 1;
		for (j = 1; j <= len - 1; j++)
			pow2 *= 2;
		for (j = 1; j <= len; j++)
		{
			digit = n / pow2;
			_putchar(digit + '0');
			count++;
			n -= digit * pow2;
			pow2 /= 2;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
