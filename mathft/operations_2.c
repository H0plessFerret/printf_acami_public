/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:27:23 by acami             #+#    #+#             */
/*   Updated: 2021/05/17 19:38:31 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathft.h"

uint64_t	ft_newnum_overflow_basic(t_strdouble *a, t_strdouble *b)
{
	uint64_t	count;
	t_strdouble	*buff;
	int16_t		curr_num;

	if (a->power < b->power)
	{
		buff = b;
		b = a;
		a = buff;
	}
	count = 0;
	while (count < a->num_len)
	{
		curr_num = a->number[count] - '0';
		if (((int64_t)(a->power - count) <= b->power)
			&& ((int64_t)(a->power - count) >= b->last_sig_digit))
			curr_num += b->number[count - (a->power - b->power)];
		if (curr_num < 9)
			return (0);
		if (curr_num >= 10)
			return (1);
		++count;
	}
	return (0);
}

uint64_t	ft_newnum_underflow_basic(t_strdouble *a, t_strdouble *b)
{
	uint64_t	count;

	count = 0;
	if (a->power == b->power)
		while (a->number[count] == b->number[count])
			++count;
	return (count);
}

static void	ft_addition_alg(t_strdouble *a, t_strdouble *b, t_strdouble *res)
{
	int64_t	max_power;
	int64_t	curr_power;
	int16_t	carry_over;
	int16_t	curr_elem;

	if (a->last_sig_digit < b->last_sig_digit)
		curr_power = a->last_sig_digit;
	else
		curr_power = b->last_sig_digit;
	if (a->power < b->power)
		max_power = b->power + 1;
	else
		max_power = a->power + 1;
	carry_over = 0;
	while (curr_power < max_power)
	{
		curr_elem = ft_add_digits(a, b, curr_power, &carry_over);
		res->number[res->power - curr_power] = curr_elem + '0';
		++curr_power;
	}
	if (carry_over != 0)
		res->number[0] = carry_over + '0';
}

t_strdouble	*ft_add_sd(t_strdouble *a, t_strdouble *b)
{
	t_strdouble	*res;
	uint64_t	new_len;

	if (a->is_negative != b->is_negative)
		return (ft_substract_sd(a, b));
	res = ft_sd_init();
	if (res != NULL)
	{
		res->is_negative = a->is_negative;
		new_len = ft_newnum_len_basic(a, b) + ft_newnum_overflow_basic(a, b);
		if (a->power > b->power)
			res->power = a->power;
		else
			res->power = b->power;
		res->power += ft_newnum_overflow_basic(a, b);
		if (ft_resize_number(res, new_len))
			ft_addition_alg(a, b, res);
	}
	return (res);
}

t_strdouble	*ft_substract_sd(t_strdouble *a, t_strdouble *b)
{
	return (NULL);
}
