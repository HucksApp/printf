#include "main.h"


/**
 * _print_chars - Prints the contents of the buffer
 * @buffer: Array of chars (string)
 * @buffer_index: Index at which to add next char
 */
void _print_chars(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);
	*buffer_index = 0;
}


/**
 * _print_char - Prints a char using
 * buffer string
 * @ap: list of args
 * @buffer: array of formated strings
 * @size: Size specifier
 * @width: Width
 * @precision: Precision
 * @flag:  passed flags
 * Return: printer counter
 */
int _print_char(va_list ap, char buffer[],
	int flag, int width, int precision, int size)
{

	char ch = va_arg(ap, int);

	return (_write_char(ch, buffer, flag, width, precision, size));
}



/**
 * _putchar - writes the character c to stdout
 * @ch: The character to print
 * Return: On success 1.
 * or -1
 */
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}




/**
 * _print_percent - Prints  percentage
 * @ap: List of args
 * @buffer: Buffer array of formated strings
 * @width: width.
 * @precision: Precision
 * @flag:  passed flags
 * @size: Size specifier
 * Return: printer counter
 */
int _print_percentage(va_list ap, char buffer[],
	int flag, int width, int precision, int size)
{
	UNUSED_VAR(width);
	UNUSED_VAR(ap);
	UNUSED_VAR(precision);
	UNUSED_VAR(buffer);
	UNUSED_VAR(flag);
	UNUSED_VAR(size);

	return (_putchar('%'));
}

