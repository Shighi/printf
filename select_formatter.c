#include "main.h"

/**
 * select_formatter - Select formatter function for specifier
 * @s: The format specifier character
 *
 * Return: Pointer to the appropriate formatter function
 */
int (*select_formatter(char s))(va_list, format_flags *)
{
	fh func_arr[] = {
		{'i', format_integer},
		{'s', format_string},
		{'c', format_char},
		{'d', format_integer},
		{'u', format_unsigned},
		{'x', format_hex_lower},
		{'X', format_hex_upper},
		{'b', format_binary},
		{'o', format_octal},
		{'R', format_rot13},
		{'r', format_reverse},
		{'S', format_unprintable},
		{'p', format_address},
		{'%', format_percent}
	};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arr[i].specifier == s)
			return (func_arr[i].func);
	return (NULL);
}
