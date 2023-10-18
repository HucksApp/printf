#include "main.h"

/**
 * _putoct - Print Format finder
 * @n: number to be converted
 * @count: printer counter
 * Return: NULL
*/

void _putoct(long n, int *count)
{
	unsigned int nm, countn = 0, i, power8;
	int oct_d;


	if (n != 0)
	{
		nm = n;
		while (nm != 0)
		{
			nm /= 8;
			countn++;
		}
		power8 = 1;
		i = countn - 1;
		while (i--)
			power8 *= 8;

		i = countn;
		while (i--)
		{
			oct_d =  n / power8;
			_putchar(oct_d + '0');
			(*count)++;
			n -= oct_d * power8;
			power8 /= 8;
		}
	}
	else
	{
		_putchar('0');
		(*count)++;
	}

}


/**
 * _print_oct- Print octal
 *@i: number to be converted
 * Return: printer counter (int)
*/
int _print_oct(va_list i)
{
	unsigned int oc;
	int count = 0;

	oc = va_arg(i, unsigned int);

	_putoct(oc, &count);
	return (count);
}

