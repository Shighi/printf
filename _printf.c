#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * _printf - Custom printf-like function
 * @format: Format string with conversion specifiers
 * @...: Variable number of arguments to format
 *
 * Return: Number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	int (*format_func)(va_list, format_flags *);
	const char *curr_char;
	va_list args;
	format_flags flags = {0, 0, 0};
	int char_count = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (curr_char = format; *curr_char; curr_char++)
	{
		if (*curr_char == '%')
		{
			curr_char++;
			if (*curr_char == '%')
			{
				char_count += output_char('%');
				continue;
			}
			while (parse_flags(*curr_char, &flags))
				curr_char++;
			format_func = select_formatter(*curr_char);
			char_count += (format_func)
				? format_func(args, &flags)
				: _printf("%%%c", *curr_char);
		}
		else
			char_count += output_char(*curr_char);
	}
	output_char(-1);
	va_end(args);
	return (char_count);
}
