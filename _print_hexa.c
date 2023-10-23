#include "main.h"

/**
 * _print_hexa - Prints a hex
 * @ap: List of arg
 * @map: Array of values
 * @buffer: Buffer array of formated string
 * @flag: flags
 * @flag_ch: active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: printer counter
 */
int _print_hexa(va_list ap, const char map[], char buffer[],
	int flag, char flag_ch, int width, int precision, int size)
{
	int index = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(ap, unsigned long int);
	unsigned long int init_num = num;

	UNUSED_VAR(width);
	num = _convert_unsignedi_size(num, size);
	if (num == 0)
		buffer[index--] =  ATI_ORIGIN;
	buffer[BUFFER_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[index--] = map[num % 16];
		num /= 16;
	}
	if (flag & HASH_FLG && init_num != 0)
	{
		buffer[index--] = flag_ch;
		buffer[index--] =  ATI_ORIGIN;
	}
	index++;
	return (_write_unsignd(0, index, buffer, flag, width, precision, size));
}








/**
 * print_hexadecimal - Prints an unsigned number in hex
 * @ap: List of args
 * @buffer: Buffer array of formated strings
 * @flag:  passed flags
 * @width: width
 * @precision: Precision
 * @size: Size specifier
 * Return: printer counter
 */
int _print_hexa_x(va_list ap, char buffer[],
	int flag, int width, int precision, int size)
{
	return (_print_hexa(ap, "0123456789abcdef", buffer,
		flag, 'x', width, precision, size));
}




/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @ap: List of args
 * @buffer: Buffer array of formated strings
 * @flag:  passedflags
 * @width: width.
 * @precision: Precision
 * @size: Size specifier
 * Return: printer counter
 */

int _print_hexa_X(va_list ap, char buffer[],
	int flag, int width, int precision, int size)
{
	return (_print_hexa(ap, "0123456789ABCDEF", buffer,
		flag, 'X', width, precision, size));
}

