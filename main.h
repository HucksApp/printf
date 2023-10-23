#ifndef MAIN_H
#define MAIN_H

/*Standard Libs*/
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <unistd.h>



/*constants*/
#define FMT_SYB '%'
#define BUFFER_SIZE 1024
#define ATI_ORIGIN '0'


/*sizes*/
#define SHORT_SIZE 1
#define LONG_SIZE 2




/**flags ( - + 0 #, space)*/
#define MINUS_FLG 1
#define PLUS_FLG 2
#define ZERO_FLG 4
#define HASH_FLG 8
#define SPACE_FLG 16



/*type casting Unused Variable*/

#define UNUSED_VAR(x) (void)(x)



/**
* struct fmt - Struct fmt
* @fmt: The format Specifier
* @fn: The function associated
*/
typedef struct fmt
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);

} print_format;




/**
* struct flag - Struct flag
*
* @c: character identifier
* @i: int value of c
*/

typedef struct  flag
{
char c;
int i;
} flag;




/*Utility general functions*/
int _is_printable_char(char ch);
int _append_hexa(char ascii_fmt, char buffer[], int index);
int _is_digit(char);
long int _convert_int_size(long int num, int size);
long int _convert_unsignedi_size(unsigned long int num, int size);
int _is_digit(char ch);



/*Functions*/

int _printf(const char *format, ...);

int _print_formater(const char *fmt, int *index, va_list ap,
	char buffer[], int flag, int width, int precision, int size);


/*function format and prints char or string*/

void _print_chars(char buffer[], int *buffer_index);
int _putchar(char ch);
int _print_char(va_list ap, char buffer[],
	int flag, int width, int precision, int size);

int _print_string(va_list ap, char buffer[],
	int flag, int width, int precision, int size);

int _print_percentage(va_list ap, char buffer[],
	int flag, int width, int precision, int size);

int _print_reverse(va_list ap, char buffer[],
	int flag, int width, int precision, int size);


int _print_rot13(va_list ap, char buffer[],
	int flag, int width, int precision, int size);

int _print_non_printable(va_list ap, char buffer[],
	int flag, int width, int precision, int size);





/*formatting helper functions*/

int _get_flags(const char *str, int *n);
int _get_size(const char *str, int *n);
int _get_width(const char *format, int *n, va_list ap);
int _get_precision(const char *format, int *n, va_list ap);



/*prints Binary*/
int _print_binary(va_list ap, char buffer[],
	int flag, int width, int precision, int size);



/*print formated integers*/

int _print_int(va_list ap, char buffer[],
	int flag, int width, int precision, int size);

int _print_unsigned(va_list ap, char buffer[],
	int flag, int width, int precision, int size);

int _print_octal(va_list ap, char buffer[],
	int flag, int width, int precision, int size);


/*prints hex*/

int _print_hexa_x(va_list ap, char buffer[],
	int flag, int width, int precision, int size);
int _print_hexa_X(va_list ap, char buffer[],
	int flag, int width, int precision, int size);

int _print_hexa(va_list ap, const char map[],
	char buffer[], int flag, char flag_ch, int width, int precision, int size);








/*prints Address*/
int _print_pointer(va_list ap, char buffer[],
	int flag, int width, int precision, int size);





/*Character writer types formatter functions*/

int _write_char(char c, char buffer[],
	int flag, int width, int precision, int size);

int _write_pointer(char buffer[], int index, int length,
	int width, int flag, char pad, char c, int pad_start);

int _write_numb(int index, char buffer[], int flag, int width,
	int prec, int length, char pad, char c);

int _write_unsignd(int is_negative, int index, char buffer[],
	int flag, int width, int precision, int size);

int _write_number(int is_positive, int index, char buffer[],
	int flag, int width, int precision, int size);

#endif

