#include "main.h"

/**
 * _isdigit - check if digit
 * @c: character
 *
 * Return: 1 digit, 0 not a digit
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length
 * @s: string
 *
 * Return: length
 */
int _strlen(char *s)
{
	int i;

	i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - print a number
 * @s: the number
 * @params: params struct
 *
 * Return: number
 */
int print_number(char *s, params_t *params)
{
	unsigned int i;
	int negative;

	i = _strlen(s);
	negative = (!params->is_unsign && *s == '-');

	if (!params->precision && *s == '0' && !s[1])
		s = "";
	if (negative)
	{
		s++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--s = '0';
	if (negative)
		*--s = '-';
	if (!params->has_minus)
		return (print_number_shift_right(s, params));
	else
		return (print_number_shift_left(s, params));
}

/**
 * print_number_shift_right - printf a number
 * @s: string
 * @params: params struct
 *
 * Return: void
 */
int print_number_shift_right(char *s, params_t *params)
{
	unsigned int n, negative, negative2, i;
	char pad_char = ' ';

	n = 0;
	i = _strlen(s);

	if (params->has_zero && !params->has_minus)
		pad_char = '0';
	negative = negative2 = (!params->is_unsign && *s == '-');
	if (negative && i < params->width
			&& pad_char == '0'
			&& !params->has_minus)
		s++;
	else
		negative = 0;
	if ((params->has_plus && !negative2) ||
			(!params->has_plus && params->has_space
			 && negative2))
		i++;
	if (negative && pad_char == '0')
		n += _putchar('-');
	if (params->has_plus && !negative2 && pad_char == '0'
			&& !params->is_unsign)
		n += _putchar('+');
	else if (!params->has_plus && params->has_space &&
		!negative2 && !params->is_unsign && params->has_zero)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (negative && pad_char == ' ')
		n += _putchar('-');
	if (params->has_plus && !negative2 && pad_char == ' ' &&
			!params->is_unsign)
		n += _putchar('+');
	else if (!params->has_plus && params->has_space && !negative2
	&& !params->is_unsign && !params->has_zero)
		n += _putchar(' ');
	n += _puts(s);
	return (n);
}

/**
 * print_number_shift_left - print number left shift
 * @s: string
 * @params: params struct
 *
 * Return: chars
 */
int print_number_shift_left(char *s, params_t *params)
{
	unsigned int n, negative, negative2, i;
	char pad_char;

	n = 0;
	i = _strlen(s);

	if (params->has_zero && !params->has_minus)
		pad_char = '0';
	negative2 = negative = (!params->is_unsign && *s == '-');
	if (negative && i < params->width && pad_char == '0' &&
		!params->has_minus)
		s++;
	else
		negative = 0;

	if (params->has_plus && !negative2 && !params->is_unsign)
		n += _putchar('+'), i++;
	else if (params->has_space && !negative2 && !params->is_unsign)
		n += _putchar(' '), i++;
	n += _puts(s);
	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}
