#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <unistd.h>

#define FMT_SYB '%'

int _putchar(char c);
int _print_char(va_list char_c);
int _print_int(va_list i);
void _putint(long n, int *count);
int _print_string(va_list str);
int _print_oct(va_list i);
int _print_hexx(va_list h);
int _print_hexX(va_list h);
int _print_rev(va_list rv);
int _printf(const char *str, ...);
int _print_unsig(va_list u);
int _print_rot13(va_list R);


/**
  * struct prt_fmt - Structure print format
  *
  * @spc: The  Specifiers character
  * @fn: The function associated
  * @str: String to be printed
  */
typedef struct prt_fmt
{
	char *spc;
	int (*fn)(va_list);
} prt_fmt;

#endif

