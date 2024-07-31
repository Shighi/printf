#include "main.h"

/**
 * format_hex_lower - Format and print unsigned int in lowercase hex
 * @l: va_list containing the number to print
 * @f: Pointer to format flags
 *
 * Return: Number of characters printed
 */
int format_hex_lower(va_list l, format_flags *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = num_to_str(num, 16, 1);
	int count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += output_str("0x");
	count += output_str(str);
	return (count);
}

/**
 * format_hex_upper - Format and print unsigned int in uppercase hex
 * @l: va_list containing the number to print
 * @f: Pointer to format flags
 *
 * Return: Number of characters printed
 */
int format_hex_upper(va_list l, format_flags *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = num_to_str(num, 16, 0);
	int count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += output_str("0X");
	count += output_str(str);
	return (count);
}

/**
 * format_binary - Format and print unsigned int in binary
 * @l: va_list containing the number to print
 * @f: Pointer to format flags (unused in this function)
 *
 * Return: Number of characters printed
 */
int format_binary(va_list l, format_flags *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = num_to_str(num, 2, 0);

	(void)f;
	return (output_str(str));
}

/**
 * format_octal - Format and print unsigned int in octal
 * @l: va_list containing the number to print
 * @f: Pointer to format flags
 *
 * Return: Number of characters printed
 */
int format_octal(va_list l, format_flags *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = num_to_str(num, 8, 0);
	int count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += output_char('0');
	count += output_str(str);
	return (count);
}
