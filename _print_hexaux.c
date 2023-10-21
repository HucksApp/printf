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

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

