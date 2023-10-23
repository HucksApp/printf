#include "main.h"



/**
* _print_string - Prints a string
* @ap: list of args
* @precision: Precision
* @buffer: Buffer array of formated strings
* @width: width.
* @flag:  passed flags
* @size: Size specifier
* Return: printer counter
*/
int _print_string(va_list ap, char buffer[],
int flag, int width, int precision, int size)
{
int iter, len = 0;
char *str = va_arg(ap, char *);

UNUSED_VAR(size);
UNUSED_VAR(flag);
UNUSED_VAR(width);
UNUSED_VAR(buffer);
UNUSED_VAR(precision);
if (str == NULL)
{
str = "(null)";
if (precision >= 6)
str = "      ";
}
while (str[len] != '\0')
len++;

if (precision >= 0 && precision < len)
len = precision;

if (width > len)
{
if (flag & MINUS_FLG)
{
write(1, &str[0], len);
for (iter = width - len; iter > 0; iter--)
_putchar(' ');
return (width);
}
else
{
for (iter = width - len; iter > 0; iter--)
_putchar(' ');
write(1, &str[0], len);
return (width);
}
}

return (write(1, str, len));
}





/**
* _print_reverse - prints strings in reverse.
* @ap: list of args
* @precision: Precision
* @buffer: Buffer array of formated strings
* @width: width.
* @flag:  passed flags
* @size: Size specifier
* Return: printer counter
*/

int _print_reverse(va_list ap, char buffer[],
int flag, int width, int precision, int size)
{

	int iter, count = 0;
	char *str;

	UNUSED_VAR(flag);
	UNUSED_VAR(size);
	UNUSED_VAR(width);
	UNUSED_VAR(buffer);
	str = va_arg(ap, char *);
	if (str == NULL)
	{
		UNUSED_VAR(precision);
		str = ")Null(";
	}
	for (iter = 0; str[iter]; iter++)
		;

	for (iter = iter - 1; iter >= 0; iter--)
	{
		char ch = str[iter];

		_putchar(ch);
		count++;
	}
	return (count);
}

