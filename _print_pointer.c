#include "main.h"


/**
 * _print_pointer - prints pointers
 * @var_v: args value
 * Return: printer counter (int)
 */


int _print_pointer(va_list var_v)
{
	int ptrc, iter;
	long int m;
	void *ptr;
	char *s = "(nil)";


	ptr = va_arg(var_v, void*);
	if (ptr == NULL)
	{
		for (iter = 0; s[iter] != '\0'; iter++)
			_putchar(s[iter]);
		return (iter);
	}
	m = (unsigned int long) ptr;
	_putchar('0');
	_putchar('x');
	ptrc = _print_hexaux(m);
	ptrc += 2;
	return (ptrc);

}
