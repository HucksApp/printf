#include "main.h"
/**
* _print_hexaux - prints an hexgecimal number.
* @n: arguments.
* Return: counter.
*/
int _print_hexaux(unsigned long int n)
{
	long int iter, *arr, len = 0;
	unsigned long int cpy = n;

	while (n / 16 != 0)
	{
		n /= 16;
		len++;
	}
	arr = (long int *) malloc(sizeof(int) * (len + 1));
	for (iter = 0; iter <= len; iter++)
	{
		arr[iter] = cpy % 16;
		cpy /= 16;
	}
	iter = len + 1;
	while (iter--)
	{
		if (arr[iter] > 9)
			arr[iter] = arr[iter] + 39;
		_putchar(arr[iter] + '0');
	}
	free(arr);
	return (len);
}
