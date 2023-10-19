#include "main.h"
/**
 * _print_char - Prints character
 * @char_c: Character to be printed
 *
 * Return: 1
*/

int _print_char (va_list char_c)
{
	unsigned char char_n;

	char_n = va_arg(char_c, int);
	_putchar(char_n);
	return (1);
}




/**
 * _print_percentage - prints %
 * @char_c: unused variable
 * Return: 1.
 */
int _print_percentage(va_list char_c)
{
	(void)char_c;
	_putchar('%');
	return (1);
}

