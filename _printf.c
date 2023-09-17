#include "main.h"

/**
 * _printf - similar to prinf
 * @format: format string
 *
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	unsigned int sum;
	va_list arg;
	char *ptr, *start;
	params_t params = PARAMS;

	sum = 0;
	va_start(arg, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (1);
	for (ptr = (char *) format; *ptr; ptr++)
	{
		init_params(&params);
		if (*ptr != '%')
		{
			sum += _putchar(*ptr);
			continue;
		}
		start = ptr;
		ptr++;
		while (get_flag(ptr, &params))
			ptr++;
		ptr = get_wid(ptr, arg, &params);
		ptr = get_prec(ptr, arg, &params);
		if (get_mod(ptr, &params))
			ptr++;
		if (!get_specifier(ptr))
			sum += print_range(start, ptr,
			params.is_l || params. is_h ? ptr - 1 : 0);
		else
			sum += get_func(ptr, arg, &params);
	}
	_putchar(FLUSH_BUFFER);
	va_end(arg);
	return (sum);
}
