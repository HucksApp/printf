#include "main.h"





/**
 * _print_octal - prints  numbers in octal
 * @ap: List of args
 * @buffer: Buffer array of formated strings
 * @flag:  passed flags
 * @width: width.
 * @precision: Precision
 * @size: Size specifier
 * Return: printer counter
 */
int _print_octal(va_list ap, char buffer[],
	int flag, int width, int precision, int size)
{
	unsigned long int init_num, num;
	int index = BUFFER_SIZE - 2;

	num = va_arg(ap, unsigned long int);
	init_num = num;

	UNUSED_VAR(width);
	num = _convert_unsignedi_size(num, size);
	if (num == 0)
		buffer[index--] =  ATI_ORIGIN;
	buffer[BUFFER_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[index--] = (num % 8) +  ATI_ORIGIN;
		num /= 8;
	}
	if (flag & HASH_FLG && init_num != 0)
		buffer[index--] =  ATI_ORIGIN;
	index++;
	return (_write_unsignd(0, index, buffer, flag, width, precision, size));
}

