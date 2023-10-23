#include "main.h"

/**
* _get_flags - Check for the passed flagg
* @str: formated string
* @n: current index of buffer.
*
* Return: Flag:
*/

int _get_flags(const char *str, int *n)
{
	int iter, current_index;
	int flags = 0;
	flag FLAGS_LIST[] = {
	{'-', MINUS_FLG},
	{' ', SPACE_FLG},
	{'+', PLUS_FLG},
	{'0', ZERO_FLG},
	{'#', HASH_FLG},
	{'\0', 0}
	};

	for (current_index = *n + 1; str[current_index]
		!= '\0'; current_index++)
	{
		for (iter = 0; FLAGS_LIST[iter].c != '\0'; iter++)
		if (str[current_index] == FLAGS_LIST[iter].c)
		{
			flags |= FLAGS_LIST[iter].i;
			break;
		}
		if (FLAGS_LIST[iter].i == 0)
		break;
		}

		*n = current_index - 1;
		return (flags);
}

