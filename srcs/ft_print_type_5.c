/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 23:35:24 by acami             #+#    #+#             */
/*   Updated: 2021/05/17 14:01:58 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_print_type.h"

long double	ft_pow_base(int8_t base, int8_t power)
{
	long double	res;

	res = 1.;
	while (power < 0)
	{
		++power;
		res /= base;
	}
	while (power > 0)
	{
		--power;
		res *= base;
	}
	return (res);
}

void	ft_correct_bad_precision(long double *nbr, int8_t *nbr_power,
int8_t base)
{
	if (*nbr < 1)
	{
		*nbr *= base;
		++(*nbr_power);
	}
	if (*nbr > base)
	{
		*nbr /= base;
		++(*nbr_power);
	}
}

void	ft_norm_float_base(long double *nbr, int8_t *nbr_power, int8_t base)
{
	*nbr /= ft_pow_base(base, *nbr_power);
	ft_correct_bad_precision(nbr, nbr_power, base);
}

int8_t	ft_find_power(long double nbr, int8_t base)
{
	int8_t	nbr_power;

	nbr_power = 0;
	if (nbr == 0.)
		return (nbr_power);
	while (nbr < 1)
	{
		nbr *= base;
		--nbr_power;
	}
	while (nbr > base)
	{
		nbr /= base;
		++nbr_power;
	}
	return (nbr_power);
}

uintmax_t	ft_abs(intmax_t num)
{
	if (num == INTMAX_MIN)
		return ((uintmax_t)INTMAX_MAX + 1);
	if (num < 0)
		return (num * -1);
	return (num);
}
