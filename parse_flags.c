#include "main.h"

/**
 * parse_flags - Parse format flags for _printf
 * @s: The flag character to parse
 * @f: Pointer to format_flags struct to update
 *
 * Return: 1 if a flag was parsed, 0 otherwise
 */
int parse_flags(char s, format_flags *f)
{
	int i = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
	}

	return (i);
}
