#include "main.h"





/**
 * _print_pointer - Prints the value of a pointer variable
 * @ap: List of args
 * @buffer: Buffer array of formated strings
 * @flag:  passed flags
 * @precision: precision
 * @width: width
 * @size: size specifier
 * Return: printer counter
 */
int _print_pointer(va_list ap, char buffer[],
				int flag, int width, int precision, int size)
{
	char c = 0, padd = ' ';
	int index = BUFFER_SIZE - 2, len = 2, padd_start = 1;
	unsigned long num_addr;

	void *addrs = va_arg(ap, void *);
	const char MAP[] = "0123456789abcdef";

	UNUSED_VAR(width);
	UNUSED_VAR(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFFER_SIZE - 1] = '\0';
	UNUSED_VAR(precision);

	num_addr = (unsigned long)addrs;
	while (num_addr > 0)
	{
		buffer[index--] = MAP[num_addr % 16];
		num_addr /= 16;
		len++;
	}
	if ((flag & ZERO_FLG) && !(flag & MINUS_FLG))
		padd = ATI_ORIGIN;
	if (flag & PLUS_FLG)
		c = '+', len++;
	else if (flag & SPACE_FLG)
		c = ' ', len++;

	index++;
	return (_write_pointer(buffer, index, len,
			width, flag, padd, c, padd_start));
}

