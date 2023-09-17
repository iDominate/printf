#include "main.h"


/**
 * _puts - similar to puts
 * @s: the string
 *
 * Return: length of string
 */
int _puts(char *s)
{
	char *a;

	a = s;
	while (*s)
		_putchar(*s++);
	return (s - a);
}

/**
 * _putchar - write to stdout
 *
 * @c: character
 *
 * Return: 1(Success) | -1 (Failure)
 */
int _putchar(int c)
{
	static int i;
	static char buffer[BUFFER_SIZE];

	if (c == FLUSH_BUFFER || i >= BUFFER_SIZE)
	{
		write(1, &buffer, i);
		i = 0;
	}
	if (c != FLUSH_BUFFER)
		buffer[i++] = c;
	return (1);
}
