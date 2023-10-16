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

