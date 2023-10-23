#include "main.h"

/**
 * _is_printable_char - Evaluates if a char is printable
 * @ch: Char to be evaluated
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int _is_printable_char(char ch)
{
	if (ch >= 32 && ch < 127)
		return (1);
	return (0);
}

/**
 * _append_hexa - Append ascci hex code to buffer
 * @buffer: Array of formated chars.
 * @index: Index .
 * @ascii_fmt: ASSCI equal rep.
 * Return: 3
 */
int _append_hexa(char ascii_fmt, char buffer[], int index)
{
	const char MAP[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_fmt < 0)
		ascii_fmt *= -1;
	buffer[index++] = '\\';
	buffer[index++] = 'x';
	buffer[index++] = MAP[ascii_fmt / 16];
	buffer[index] = MAP[ascii_fmt % 16];
	return (3);
}

/**
 * _is_digit - Verifies the char c is a digit
 * @ch: Char
 * Return: 1 if c is a digit, 0 if false
 */
int _is_digit(char ch)
{
	if (ch >= ATI_ORIGIN && ch <= '9')
		return (1);
	return (0);
}


/**
 * _convert_unsignedi_size - Casts a number to the specified size
 * @num: number
 * @size: type size to cast to
 * Return: casted result
 */
long int _convert_unsignedi_size(unsigned long int num, int size)

{
	switch (size)
	{
	case LONG_SIZE:
		return (num);
	case SHORT_SIZE:
		return ((unsigned short)num);
	default:
		return ((unsigned int)num);
	}
}





/**
 * _convert_int_size - type cast a number to the specified size
 * @num: Number
 * @size: type size to cast to
 * Return: casted result
 */
long int _convert_int_size(long int num, int size)
{
	switch (size)
	{
	case LONG_SIZE:
		return (num);
	case SHORT_SIZE:
		return ((short int)num);
	default:
		return ((int)num);
	}

}

