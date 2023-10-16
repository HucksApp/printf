#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

#define FMT_SYB '%'

int _putchar(char c);
int _print_char(va_list char_c);
int _print_int(va_list i);
int _printf(const char *str, ...);



/**
  * struct prt_fmt - Structure print format
  *
  * @spc: The  Specifiers character
  * @fn: The function associated
  * @str: String to be printed
  */
struct prt_fmt
{
	char *spc;
	int (*fn)(va_list);
};
#endif

