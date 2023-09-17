#include "main.h"

/**
 * get_specifier - gets the function to be called
 * @s: specifier
 *
 * Return: NULL(Failure) || func(Success)
 */
int (*get_specifier(char *s))(va_list arg, params_t *params)
{
	int i;
	int (*func)(va_list, params_t *);


	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_str},
		{"%", print_percentage},
		{"b", print_bin},
		{"o", print_oct},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};

	i = 0;
	func = NULL;
	while (specifiers[i].format)
	{
		if (specifiers[i].format[0] == *s)
			func = specifiers[i].func;
		i++;
	}
	return func;
}

/**
 * get_func - find the fomat function
 * @s: format string,
 * @arg: args
 * @params: param struct
 *
 * Return: NULL(Failure) || func(Success)
 */
int get_func(char *s, va_list arg, params_t *params)
{
	int (*func)(va_list, params_t *) = get_specifier(s);

	if (func)
		return (func(arg, params));
	return (0);
}

/**
 * get_flag - get flag
 * @s: character
 * @params: params struct
 *
 * Return: 0(Failure) || 1(Success)
 */
int get_flag(char *s, params_t *params)
{
	int i;

	i = 0;

	switch (*s)
	{
		case '+':
			i = params->has_plus = 1;
			break;
		case ' ':
			i = params->has_space = 1;
			break;
		case '#':
			i = params->has_hash = 1;
			break;
		case '-':
			i = params->has_minus = 1;
			break;
		case '0':
			i = params->has_zero = 1;
			break;
	}
	return (i);
}

/**
 * get_mod - get modifier
 * @s: character
 * @params: params struct
 *
 * Return: 1(Success) || 0(Failure)
 */
int get_mod(char *s, params_t *params)
{
	int i;

	i = 0;

	switch (*s)
	{
		case 'l':
			i = params->is_l = 1;
			break;
		case 'h':
			i = params->is_h = 1;
			break;
	}
	return (i);
}

/**
 * get_wid - gets the width
 * @s: the string
 * @params: params struct
 * @arg: args
 *
 * Return: pointer
 */
char *get_wid(char *s, va_list arg, params_t *params)
{
	int digit;

	digit = 0;

	if (*s == '*')
	{
		digit = va_arg(arg, int);
		s++;
	} else
	{
		while (_isdigit(*s))
			digit = digit * 10 + (*s++ - '0');
	}
	params->width = digit;
	return (s);
}
