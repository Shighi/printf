#include "main.h"
#include <unistd.h>

/**
 * output_char - Buffer a character for output
 * @c: The character to buffer
 *
 * Return: Always returns 1
 */
int output_char(char c)
{
	static char buf[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);
		i = 0;
	}
	if (c != -1)
	{
		buf[i] = c;
		i++;
	}
	return (1);
}

/**
 * output_str - Output a string
 * @str: The string to output
 *
 * Return: Number of characters output
 */
int output_str(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		output_char(str[i]);
	return (i);
}
