/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:59:50 by acami             #+#    #+#             */
/*   Updated: 2021/05/17 17:05:37 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathft.h"

static size_t	ft_intlen(int64_t number)
{
	size_t	res;
	int64_t	divider;

	res = 19;
	divider = -1000000000000000000;
	if (number > 0)
		number *= -1;
	while (number / divider == 0 && divider != -1)
	{
		divider /= 10;
		--res;
	}
	return (res);
}

static int64_t	basic_pow(int64_t x, int64_t n)
{
	int64_t	res;

	res = x;
	if (n == 0)
		return (1);
	while (n > 1)
	{
		res *= x;
		--n;
	}
	return (res);
}

t_strdouble	*ft_i_to_sd(int64_t number)
{
	t_strdouble	*res;
	uint32_t	current_pos;
	int64_t		divider;

	res = ft_sd_init();
	if (res != NULL)
	{
		res->power = ft_intlen(number) - 1;
		if (!ft_resize_number(res, res->power + 1))
			return (ft_free_sd(res));
		if (number >= 0)
			number *= -1;
		else
			res->is_negative = true;
		current_pos = 0;
		divider = -1 * basic_pow(10, res->power);
		while (divider != 0)
		{
			res->number[current_pos] = number / divider % 10 + '0';
			divider = divider / 10;
			++current_pos;
		}
	}
	res->last_sig_digit = res->power + 1 - res->num_len;
	return (res);
}
