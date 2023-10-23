#include "main.h"





/**
* _get_size - Calculates the size to cast the argument
* @str: Formatted string in which to print the arguments
* @n: List of arguments to be printed
*
* Return: Precision.
*/
int _get_size(const char *str, int *n)
{
	int size = 0;
	int current_index = *n + 1;

	switch (str[current_index])
	{
	case 'l':
		size = LONG_SIZE;
		break;
	case 'h':
		size = SHORT_SIZE;
	default:
		break;
	}

	switch (size)
	{
	case 0:
		*n = current_index - 1;
	break;
	default:
		*n = current_index;
		break;
	}

	return (size);

}

