#include "main.h"

/**
 * convert - convert to various numbering systems
 * @num: number
 * @base: base
 * @flags: flags
 * @params: params struct
 *
 * Return: string
 */
char *convert(long int num, int base, int flags, 
		__attribute__((unused)) params_t *params)
{
	static char *arr;
	static char buffer[50];
	char sign;
	char *ptr;
	unsigned long n;

	sign = 0;
	n = num;

	if (!(flags & CONVERT_TO_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	arr = flags & CONVERT_TO_LOWERCASE ? "01234567890abcdef" :
		"0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = arr[(n - 1) % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);

}

/**
 * print_unsigned - print the number unsigned
 * @arg: arg
 * @params: params struct
 *
 * Return: number
 */
int print_unsigned(va_list arg, params_t *params)
{
	unsigned long l;

	l = 0;

	if (params->is_l)
		l = (unsigned long) va_arg(arg, unsigned long);
	else if (params->is_h)
		l = (unsigned short int) va_arg(arg, unsigned int);
	else
		l = (unsigned int) va_arg(arg, unsigned int);
	params->is_unsign = 1;
	return (print_number(convert(l, 10, CONVERT_TO_UNSIGNED, params), params));
}

/**
 * print_address - prints address
 * @arg: args
 * @params: params struct
 *
 * Return: number
 */
int print_address(va_list arg, params_t *params)
{
	unsigned long int n = va_arg(arg, unsigned long int);
	char *s;

	if (!n)
		return (_puts("nil"));
	s = convert(n, 16, CONVERT_TO_UNSIGNED | CONVERT_TO_LOWERCASE, params);
	*--s = 'x';
	*--s = '0';
	return (print_number(s, params));
}
