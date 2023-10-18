#include "main.h"



/**
 * _print_string - Prints a string,
 * Helper Function to _printf
 * @str: The string to print
 *
 * Return: printed character count
*/

int _print_string(va_list str)
{
	int string_count = 0;
	char *char_string;

	char_string = va_arg(str, char*);
	while (*char_string != '\0')
	{
		_putchar(*char_string);
		string_count++;
		char_string++;
	}

	(void) char_string;
	return (string_count);
}

