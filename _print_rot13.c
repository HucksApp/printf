#include "main.h"

/**
  * _print_rot13 - convert string to rot13.
  * @R: string to convert
  * Return: printer counter
  */
int _print_rot13(va_list R)
{
	char *n;
	int j, i, count = 0;
	char inp[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz";
	char outp[] = "NOPQRSTUVWXYZABCDEFGHIJKLM nopqrstuvwxyzabcdefghijklm";

	n = va_arg(R, char *);
	if (n == NULL)
		n = "(null)";
	for (j = 0; n[j] != '\0'; j++)
	{
		for (i = 0; inp[i] != '\0'; i++)
		{
			if (n[j] == inp[i])
			{
				_putchar(outp[i]);
				count++;
				break;
			}
		}
	}
	return (count);
}
