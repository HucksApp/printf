#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _find_fmtf - Print Format finder
 *
 * Return: NULL or Format Function
*/

int (* _find_fmtf(const char *fmspr))(va_list)
{
	unsigned int index = 0;

	prt_fmt prt_fmts[] = {

	{"c", _print_char},
	{"i", _print_int},
	{NULL, NULL}

	};



	while (prt_fmts[index].spc)
	{

		if (*(prt_fmts[index].spc) == *fmspr)
			return (prt_fmts[index].fn);
		index++;
	}
	return (NULL);

}





/**
 * _printf - Print Format finder
 * @str: Formated String
 *@...: variables to be inserted into the stream
 * Return: NULL or Format Function
*/

int _printf(const char *str, ...)
{

	va_list ap;
	unsigned int print_count = 0, char_count = 0;
	int (*fmt)(va_list);

	if (!str || (str[0] == FMT_SYB && str[1] == '\0'))
		return (-1);

	va_start(ap, str);

	while (str[char_count])
	{
		switch (str[char_count])
		{
		case ('\0'):
			return (print_count);
		case (FMT_SYB):
			if (!str[char_count + 1])
				return (-1);

			fmt = _find_fmtf(&(str[char_count + 1]));
			if (fmt != NULL)
			{
				print_count += fmt(ap);
				char_count += 2;
			}
			break;

		default:
			_putchar(str[char_count]);
			print_count++;
			char_count++;
			break;
		}

	}

	va_end(ap);
	return (print_count);
}

