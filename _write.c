#include "main.h"





/**
 * _write_char - Prints a string
 * @c: char format.
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int _write_char(char c, char buffer[],
	int flag, int width, int precision, int size)
{
	int index = 0;
	char pad = ' ';

	UNUSED_VAR(precision);
	UNUSED_VAR(size);

	if (flag & ZERO_FLG)
		pad = ATI_ORIGIN;

	buffer[index++] = c;
	buffer[index] = '\0';

	if (width > 1)
	{
		buffer[BUFFER_SIZE - 1] = '\0';
		for (index = 0; index < width - 1; index++)
			buffer[BUFFER_SIZE - index - 2] = pad;

		if (flag & MINUS_FLG)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFFER_SIZE - index - 1], width - 1));
		else
			return (write(1, &buffer[BUFFER_SIZE - index - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}


/**
 * _write_number - prints  string
 * @is_negative: Lists of arguments
 * @index: char types.
 * @buffer: Buffer array of formatted string
 * @flag:  passed  flags
 * @width:  width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int _write_number(int is_negative, int index, char buffer[],
	int flag, int width, int precision, int size)
{
	int len = BUFFER_SIZE - index - 1;
	char pad = ' ', extra_ch = 0;

	UNUSED_VAR(size);
	if ((flag & ZERO_FLG) && !(flag & MINUS_FLG))
		pad = ATI_ORIGIN;
	if (is_negative)
		extra_ch = '-';
	else if (flag & PLUS_FLG)
		extra_ch = '+';
	else if (flag & SPACE_FLG)
		extra_ch = ' ';

	return (_write_numb(index, buffer, flag, width, precision,
		len, pad, extra_ch));
}

/**
 * _write_numb - Write a number using  bufffer
 * @index: Index to start
 * @buffer: Buffer of formated chars ( formated string )
 * @width: width
 * @len: number char length
 * @prcn: Precision
 * @pad: Pading char
 * @flag: flag
 * @c:  char
 * Return: printer counter
 */
int _write_numb(int index, char buffer[], int flag, int width,
				int prcn, int len, char pad, char c)
{
	int iter, bb = BUFFER_SIZE, pad_start = 1;

	if (prcn == 0 && index == bb - 2 && buffer[index] == '0' && width == 0)
		return (0);
	if (prcn == 0 && index == BUFFER_SIZE - 2 && buffer[index] == ATI_ORIGIN)
		buffer[index] = pad = ' ';
	if (prcn > 0 && prcn < len)
		pad = ' ';
	while (prcn > len)
		buffer[--index] = ATI_ORIGIN, len++;
	if (c != 0)
		len++;
	if (width > len)
	{
		for (iter = 1; iter < width - len + 1; iter++)
			buffer[iter] = pad;
		buffer[iter] = '\0';
		if (flag & MINUS_FLG && pad == ' ')
		{
			if (c)
				buffer[--index] = c;
			return (write(1, &buffer[index], len) + write(1, &buffer[1], iter - 1));
		}
		else if (!(flag & MINUS_FLG) && pad == ' ')
		{
			if (c)
				buffer[--index] = c;
			return (write(1, &buffer[1], iter - 1) + write(1, &buffer[index], len));
		}
		else if (!(flag & MINUS_FLG) && pad == ATI_ORIGIN)
		{
			if (c)
				buffer[--pad_start] = c;
			return (write(1, &buffer[pad_start], iter - pad_start) +
				write(1, &buffer[index], len - (1 - pad_start)));
		}
	}
	if (c)
		buffer[--index] = c;
	return (write(1, &buffer[index], len));
}


/**
 * _write_unsigned - writes unsigned number
 * @is_negative: integer boolean ( 1|0 )
 * @index: buffer index to start from
 * @buffer: Array of formated chars
 * @flag: flags
 * @width: width
 * @precision: Precision
 * @size: Size specifier
 * Return: printer counter
 */
int _write_unsignd(int is_negative, int index,
	char buffer[],
	int flag, int width, int precision, int size)
{
	int iter = 0, len = BUFFER_SIZE - index - 1;
	char pad = ' ';

	UNUSED_VAR(size);
	UNUSED_VAR(is_negative);

	if (precision == 0 && index == BUFFER_SIZE - 2 && buffer[index] == ATI_ORIGIN)
		return (0);
	if (precision > 0 && precision < len)
		pad = ' ';
	while (precision > len)
	{
		buffer[--index] = ATI_ORIGIN;
		len++;
	}
	if ((flag & ZERO_FLG) && !(flag & MINUS_FLG))
		pad = ATI_ORIGIN;

	if (width > len)
	{
		for (iter = 0; iter < width - len; iter++)
			buffer[iter] = pad;
		buffer[iter] = '\0';
		if (flag & MINUS_FLG)
			return (write(1, &buffer[index], len) + write(1, &buffer[0], iter));
		else
			return (write(1, &buffer[0], iter) + write(1, &buffer[index], len));
	}
	return (write(1, &buffer[index], len));
}







/**
 * _write_pointer - writes a memory address
 * @buffer: Arrays of formated chars
 * @index: Index of char in buffer
 * @len: Length
 * @width: width
 * @flag: Flags specifier
 * @pad:  char pads
 * @c: Char
 * @pad_start: index of padding starts
 *
 * Return: printer counter
 */
int _write_pointer(char buffer[], int index, int len,
	int width, int flag, char pad, char c, int pad_start)
{
	int iter;
	char sigV = 'x';

	if (width > len)
	{
		for (iter = 3; iter < width - len + 3; iter++)
			buffer[iter] = pad;
		buffer[iter] = '\0';
		if (flag & MINUS_FLG && pad == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--index] = sigV;
			buffer[--index] = ATI_ORIGIN;
			if (c)
				buffer[--index] = c;
			return (write(1, &buffer[index], len) + write(1, &buffer[3], iter - 3));
		}
		else if (!(flag & MINUS_FLG) && pad == ' ')/* extra char to left of buffer */
		{
			buffer[--index] = sigV;
			buffer[--index] = ATI_ORIGIN;
			if (c)
				buffer[--index] = c;
			return (write(1, &buffer[3], iter - 3) + write(1, &buffer[index], len));
		}
		else if (!(flag & MINUS_FLG) && pad == '0')/* extra char to left of pad */
		{
			if (c)
				buffer[--pad_start] = c;
			buffer[1] = ATI_ORIGIN;
			buffer[2] = sigV;
			return (write(1, &buffer[pad_start], iter - pad_start) +
				write(1, &buffer[index], len - (1 - pad_start) - 2));
		}
	}
	buffer[--index] = sigV;
	buffer[--index] = ATI_ORIGIN;
	if (c)
		buffer[--index] = c;
	return (write(1, &buffer[index], BUFFER_SIZE - index - 1));
}

