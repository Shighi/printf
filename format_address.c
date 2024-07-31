#include "main.h"

/**
 * format_address - Format and print a memory address
 * @l: va_list containing the address to print
 * @f: Pointer to format flags (unused in this function)
 *
 * Return: Number of characters printed
 */
int format_address(va_list l, format_flags *f)
{
	char *str;
	unsigned long int p = va_arg(l, unsigned long int);

	register int count = 0;

	(void)f;

	if (!p)
		return (output_str("(nil)"));
	str = num_to_str(p, 16, 1);
	count += output_str("0x");
	count += output_str(str);
	return (count);
}
