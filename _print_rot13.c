#include "main.h"

/**
  * _print_rot13 - convert string to rot13.
  * @R: string to convert
  * Return: printer counter
  */

int _print_rot13(va_list R)
{
	int iter, j, count = 0, k = 0;
	char *s = va_arg(R, char*);
	char alph[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char beta[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (s == NULL)
		s = "(null)";
	for (iter = 0; s[iter]; iter++)
	{
		k = 0;
		for (j = 0; alph[j] && !k; j++)
		{
			if (s[iter] == alph[j])
			{
				_putchar(beta[j]);
				count++;
				k = 1;
			}
		}
		if (!k)
		{
			_putchar(s[iter]);
			count++;
		}
	}
	return (count);
}
