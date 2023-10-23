#include "main.h"


/**
 * _print_int - Prints integer
 * @ap: List of args
 * @buffer: Buffer array of formated strings
 * @flag:  passed flags
 * @width: width
 * @precision:Precision
 * @size: Size specifier
 * Return: printer counter
 */

int _print_int(va_list ap, char buffer[],
	int flag, int width, int precision, int size)
{
	int index = BUFFER_SIZE - 2, is_negative = 0;
	long int nm = va_arg(ap, long int);
	unsigned long int num;

	nm = _convert_int_size(nm, size);
	if (nm == 0)
		buffer[index--] = ATI_ORIGIN;

	buffer[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)nm;
	if (nm < 0)
	{
		num = (unsigned long int)((-1) * nm);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[index--] = (num % 10) + ATI_ORIGIN;
		num /= 10;
	}
	index++;
	return (_write_number(is_negative, index, buffer,
				flag, width, precision, size));
}




/**
 * _print_unsigned - Prints  unsigned int
 * @ap: List of args
 * @buffer: Buffer array of formated strings
 * @flag:  passed flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: printer counter
 */
int _print_unsigned(va_list ap, char buffer[],
	int flag, int width, int precision, int size)
{
	int index = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(ap, unsigned long int);

	num = _convert_unsignedi_size(num, size);
	if (num == 0)
		buffer[index--] = ATI_ORIGIN;
	buffer[BUFFER_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[index--] = (num % 10) +  ATI_ORIGIN;
		num /= 10;
	}
	index++;
	return (_write_unsignd(0, index, buffer, flag, width, precision, size));
}

