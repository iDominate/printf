#include "main.h"

/**
 * print_hex - prints unsigned hex
 * @arg: args
 * @params: params struct
 *
 * Return: chars
 */
int print_hex(va_list arg, params_t *params)
{
	unsigned long l;
	int c;
	char *s;

	c = 0;

	if (params->is_l)
		l = (unsigned long) va_arg(arg, unsigned long);
	else if (params->is_h)
		l = (unsigned short int) va_arg(arg, unsigned int);
	else
		l = (unsigned int) va_arg(arg, unsigned int);

	s = convert(l, 16, CONVERT_TO_UNSIGNED |
			CONVERT_TO_LOWERCASE, params);
	if (params->has_hash && l)
	{
		*--s = 'x';
		*--s = '0';
	}
	params->is_unsign = 1;
	return (c += print_number(s, params));

}

/**
 * print_HEX - prints HEX
 * @arg: args
 * @params: params struct
 *
 * Return: chars
 */
int print_HEX(va_list arg, params_t *params)
{
	unsigned long l;
	int c;
	char *s;

	c = 0;

	if (params->is_l)
		l = (unsigned long) va_arg(arg, unsigned long);
	else if (params->is_h)
		l = (unsigned short int) va_arg(arg, unsigned int);
	else
		l = (unsigned int) va_arg(arg, unsigned int);

	s = convert(l, 16, CONVERT_TO_UNSIGNED, params);
	if (params->has_hash && l)
	{
		*--s = 'X';
		*--s = '0';
	}
	params->is_unsign = 1;
	return (c += print_number(s, params));

}

/**
 * print_bin - prints binary
 * @arg: args
 * @params: params struct
 *
 * Return: int
 */
int print_bin(va_list arg, params_t *params)
{
	unsigned int n;
	char *s;
	int c;

	n = va_arg(arg, unsigned int);
	s = convert(n, 2, CONVERT_TO_UNSIGNED, params);
	c = 0;

	if (params->has_hash && n)
		*--s = '0';
	params->is_unsign = 1;
	return (c += print_number(s, params));
}

/**
 * print_oct - prints octal
 * @arg: args
 * @params: params struct
 *
 * Return: number
 */
int print_oct(va_list arg, params_t *params)
{
	unsigned long l;
	char *s;
	int c;
	
	l = c = 0;
	if (params->is_l)
		l = (unsigned long) va_arg(arg, unsigned long);
	else if(params->is_h)
		l = (unsigned short int) va_arg(arg, unsigned int);
	else
		l = (unsigned int) va_arg(arg, unsigned int);
	s = convert(l, 8, CONVERT_TO_UNSIGNED, params);

	if (params->has_hash && l)
		*--s = '0';
	params->is_unsign = 1;
	return (c += print_number(s, params));
}
