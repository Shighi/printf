#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct format_flags
{
	int plus;
	int space;
	int hash;
} format_flags;

typedef struct format_handler
{
	char specifier;
	int (*func)(va_list ap, format_flags *f);
} fh;

/* format_numbers.c */
int format_integer(va_list l, format_flags *f);
void output_number(int n);
int format_unsigned(va_list l, format_flags *f);
int digit_count(int i);

/* format_bases.c */
int format_hex_lower(va_list l, format_flags *f);
int format_hex_upper(va_list l, format_flags *f);
int format_binary(va_list l, format_flags *f);
int format_octal(va_list l, format_flags *f);

/* num_to_str.c */
char *num_to_str(unsigned long int num, int base, int lowercase);

/* _printf.c */
int _printf(const char *format, ...);

/* select_formatter.c */
int (*select_formatter(char s))(va_list, format_flags *);

/* parse_flags.c */
int parse_flags(char s, format_flags *f);

/* format_text.c */
int format_string(va_list l, format_flags *f);
int format_char(va_list l, format_flags *f);

/* output_utils.c */
int output_char(char c);
int output_str(char *str);

/* format_special.c */
int format_rot13(va_list l, format_flags *f);
int format_reverse(va_list l, format_flags *f);
int format_unprintable(va_list l, format_flags *f);

/* format_address.c */
int format_address(va_list l, format_flags *f);

/* format_percent.c */
int format_percent(va_list l, format_flags *f);

#endif
