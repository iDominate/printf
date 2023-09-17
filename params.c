#include "main.h"

/**
 * init_params - initialized stuct fields to 0
 * @params: the param struct
 *
 * Return: void
 */
void init_params(params_t *params)
{
	params->is_unsign = 0;
	params->has_plus = 0;
	params->has_space = 0;
	params->has_hash = 0;
	params->has_zero = 0;
	params->has_minus = 0;
	params->width = 0;
	params->precision = UINT_MAX;
	params->is_l = 0;
	params->is_h = 0;
}
