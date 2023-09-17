#include "main.h"

/**
 * print_char - prints character
 * @arg: args
 * @params: the params struct
 *
 * Return: number
 */
int print_char(va_list arg, params_t *params)
{
	char pad_char;
	unsigned int pad, sum, ch;

	pad_char = ' ';
	pad = 1;
	sum = 0;
	ch = va_arg(arg, int);

	if (params->has_minus)
		sum += _putchar(ch);
	while (pad++ < params->width)
		sum += _putchar(pad_char);
	if (!params->has_minus)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_int - prints an integer
 * @arg: args
 * @params: params struct
 *
 * Return: void
 */
int print_int(va_list arg, params_t *params)
{
	long l;

	l = 0;

	if (params->is_l)
		l = va_arg(arg, long);
	else if (params->is_h)
		l = (short int) va_arg(arg, int);
	else
		l = (int) va_arg(arg, int);
	return (print_number(convert(l, 10, 0, params),
				params));
}

/**
 * print_string - prints a string
 * @arg: args
 * @params: params struct
 *
 * Return: chars
 */
int print_str(va_list arg, __attribute__((unused)) params_t *params)
{
	char *s, pad_char;
	unsigned int pad, sum, i, j;

	pad = sum = i = j = 0;
	s = va_arg(arg, char *);
	pad_char = ' ';
	pad = sum = i = j = 0;

	switch ((int)(!s))
		case 1:
			s = NULL_STRING;
	j = pad = _strlen(s);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->has_minus)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*s++);
		else
			sum += _puts(s);
	}
	while (j++ < params->width)
		sum += _putchar(pad_char);
	if (!params->has_minus)
	{
		if (params->precision != UINT_MAX)
			for (; i < pad; i++)
				sum += _putchar(*s++);
		else
			sum += _puts(s);
	}
	return (sum);
}

/**
 * print_percentage - print percentage sign
 * @arg: args
 * @params: the params struct
 *
 * Return: number
 */
int print_percentage(__attribute__((unused)) va_list arg,
		__attribute__((unused)) params_t *params)
{
	return (_putchar('%'));
}

/**
 * print_S - print S
 * @arg: args
 * @params: params struct
 *
 * Return: number
 */
int print_S(va_list arg, params_t *params)
{
	char *s, *hex;
	int sum;

	s = va_arg(arg, char *);
	sum = 0;

	if ((int)(!s))
		return (_puts(NULL_STRING));
	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) ||
				*s >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*s, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += puts(hex);
		} else
		{
			sum += _putchar(*s);
		}
	}
	return (sum);
}
