#include "main.h"


/**
* _print_rot13 - print  string in rot13.
* @ap: List of args
* @buffer: Buffer array of formated strings
* @flag:  passed flags
* @width: width
* @precision: precision
* @size: size specifier
* Return: printer counter
*/
int _print_rot13(va_list ap, char buffer[],
	int flag, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int iter, j;
	int count = 0;
	const char INP[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	const char OUTP[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(ap, char *);
	UNUSED_VAR(buffer);
	UNUSED_VAR(size);
	UNUSED_VAR(flag);
	UNUSED_VAR(precision);
	UNUSED_VAR(width);
	if (str == NULL)
		str = "(AHYY)";
	for (iter = 0; str[iter]; iter++)
	{
		for (j = 0; INP[j]; j++)
		{
			if (INP[j] == str[iter])
			{
				x = OUTP[j];
				_putchar(x);
				count++;
				break;
			}
		}
		if (!INP[j])
		{
			x = str[iter];
			_putchar(x);
			count++;
		}
	}
	return (count);
}

