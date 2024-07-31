#include "main.h"

/**
 * format_percent - Format and print a percent sign
 * @l: va_list (unused in this function)
 * @f: Pointer to format flags (unused in this function)
 *
 * Return: Always returns 1 (for one character printed)
 */
int format_percent(va_list l, format_flags *f)
{
	(void)l;
	(void)f;
	return (output_char('%'));
}
