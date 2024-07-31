#include "main.h"

/**
 * num_to_str - Convert number to string in given base
 * @num: Number to convert
 * @base: Base for conversion (e.g., 10 for decimal)
 * @lowercase: Flag for lowercase hex digits
 *
 * Return: Pointer to the resulting string
 */
char *num_to_str(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
