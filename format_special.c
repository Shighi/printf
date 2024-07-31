#include "main.h"

/**
 * format_unprintable - Format string, replacing unprintable chars
 * @l: va_list containing the string to format
 * @f: Pointer to format flags (unused in this function)
 *
 * Return: Number of characters printed
 */
int format_unprintable(va_list l, format_flags *f)
{
	int i, count = 0;
	char *res;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		return (output_str("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			output_str("\\x");
			count += 2;
			res = num_to_str(s[i], 16, 0);
			if (!res[1])
				count += output_char('0');
			count += output_str(res);
		}
		else
			count += output_char(s[i]);
	}
	return (count);
}

/**
 * format_reverse - Format and print a string in reverse
 * @l: va_list containing the string to reverse
 * @f: Pointer to format flags (unused in this function)
 *
 * Return: Number of characters printed
 */
int format_reverse(va_list l, format_flags *f)
{
	int i = 0, j;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		s = "(null)";

	while (s[i])
		i++;

	for (j = i - 1; j >= 0; j--)
		output_char(s[j]);

	return (i);
}

/**
 * format_rot13 - Format and print a string in ROT13 encoding
 * @l: va_list containing the string to encode
 * @f: Pointer to format flags (unused in this function)
 *
 * Return: Number of characters printed
 */
int format_rot13(va_list l, format_flags *f)
{
	int i, j;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(l, char *);

	(void)f;
	for (j = 0; s[j]; j++)
	{
		if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
			output_char(s[j]);
		else
		{
			for (i = 0; i <= 52; i++)
			{
				if (s[j] == rot13[i])
					output_char(ROT13[i]);
			}
		}
	}

	return (j);
}
