#include "main.h"

/**
 * get_precision - gets the precision
 * @s: format string
 * @params: params struct
 * @arg: args
 *
 * Return: pointer
 */
char *get_prec(char *s, va_list arg, params_t *params)
{
	int digit;

	digit = 0;

	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		digit = va_arg(arg, int);
		s++;
	} else
	{
		while (_isdigit(*s))
			digit = digit * 10 + (*s++ - '0');
	}
	params->precision = digit;
	return (s);
}
