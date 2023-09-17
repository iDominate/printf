#include "main.h"

/**
 * print_range - print the range
 * @start: start offset
 * @until: unil a char
 * @except: execpt char
 *
 * Return: number
 */
int print_range(char *start, char *until, char *except)
{
	int sum;

	sum = 0;

	while (start <= until)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_rev - print string in reverse
 *
 * @arg: arg
 * @params: params struct
 *
 * Return: number
 */
int print_rev(va_list arg,  __attribute__((unused)) params_t *params)
{
	int len, sum;
	char *s;

	len = sum = 0;
	s = va_arg(arg, char *);
	if (s)
	{
		for (len = 0; *s; s++)
			len++;
		s--;
		while (len > 0)
		{
			sum += _putchar(*s);
			len--;
			s--;
		}
	}
	return (sum);

}

/**
 * print_rot13 - print rot13
 *
 * @arg: args
 * @params: params struct
 *
 * Return: number
 */
int print_rot13(va_list arg, __attribute__((unused)) params_t *params)
{
	int i, n, count;

	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM     nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(arg, char *);

	count = n = 0;

	for (i = 0; a[i]; i++)
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
				|| (a[i] >= 'a' && a[i] <= 'z'))
		{
			n = a[i] - 65;
			count += _putchar(arr[n]);
		} else
			count += _putchar(a[i]);
	}
	return (count);

}
