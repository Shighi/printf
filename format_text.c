#include "main.h"

/**
 * format_string - Format and print a string
 * @l: va_list containing the string to print
 * @f: Pointer to format flags (unused in this function)
 *
 * Return: Number of characters printed
 */
int format_string(va_list l, format_flags *f)
{
	char *s = va_arg(l, char *);

	(void)f;

	if (!s)
		s = "(null)";
	return (output_str(s));
}

/**
 * format_char - Format and print a character
 * @l: va_list containing the character to print
 * @f: Pointer to format flags (unused in this function)
 *
 * Return: Always returns 1 (for one character printed)
 */
int format_char(va_list l, format_flags *f)
{
	(void)f;
	output_char(va_arg(l, int));
	return (1);
}
