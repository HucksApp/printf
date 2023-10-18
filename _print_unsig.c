#include "main.h"





/**
* put_uint - unsigned integer printer
* helper function
* @n:  numbers to be printed
* @count: printer counter
* Descriptions: prints unsigned number with putchar
* Return: printer count (int)
*/

void put_uint(long n, int *count)
{
	if (n / 10)
		put_uint(n / 10, count);
	_putchar(n % 10 + '0');
	(*count)++;
}






/**
* _print_unsig - prints unsigned number
* @u: unsigned number
* Descriptions: prints unsigned number with putchar
* Return: printer count (int)
*/

int _print_unsig(va_list u)
{
	int next_var, count = 0;
	unsigned int ui;

	next_var = va_arg(u, int);
	if (next_var < 0)
	{
		ui = (UINT_MAX + 1) + next_var;
		put_uint(ui, &count);
	}
	else
		put_uint(next_var, &count);
	return (count);

}
