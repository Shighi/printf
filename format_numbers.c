#include "main.h"

/**
 * format_integer - Format and print a signed integer
 * @l: va_list containing the integer to print
 * @f: Pointer to format flags
 *
 * Return: Number of characters printed
 */
int format_integer(va_list l, format_flags *f)
{
	int n = va_arg(l, int);
	int res = digit_count(n);

	if (f->space == 1 && f->plus == 0 && n >= 0)
		res += output_char(' ');
	if (f->plus == 1 && n >= 0)
		res += output_char('+');
	if (n <= 0)
		res++;
	output_number(n);
	return (res);
}

/**
 * format_unsigned - Format and print an unsigned integer
 * @l: va_list containing the unsigned int to print
 * @f: Pointer to format flags (unused in this function)
 *
 * Return: Number of characters printed
 */
int format_unsigned(va_list l, format_flags *f)
{
	unsigned int u = va_arg(l, unsigned int);
	char *str = num_to_str(u, 10, 0);

	(void)f;
	return (output_str(str));
}

/**
 * output_number - Helper function to output a number
 * @n: The number to output
 */
void output_number(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		output_char('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		output_number(n1 / 10);
	output_char((n1 % 10) + '0');
}

/**
 * digit_count - Count the number of digits in an integer
 * @i: The integer to count digits of
 *
 * Return: Number of digits in the integer
 */
int digit_count(int i)
{
	unsigned int d = 0;
	unsigned int u;

	if (i < 0)
		u = i * -1;
	else
		u = i;
	while (u != 0)
	{
		u /= 10;
		d++;
	}
	return (d);
}
