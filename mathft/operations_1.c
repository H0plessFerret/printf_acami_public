/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:59:44 by acami             #+#    #+#             */
/*   Updated: 2021/05/17 17:18:56 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathft.h"

static int16_t	ft_strcmp(const char *s1, const char *s2)
{
	size_t	count;

	count = 0;
	while (*(s1 + count) != '\0' || *(s2 + count) != '\0')
	{
		if (*(s1 + count) != *(s2 + count))
			return ((unsigned char)(*(s1 + count))
				  - (unsigned char)(*(s2 + count)));
		++count;
	}
	return (0);
}

int16_t	ft_compare_sd(t_strdouble *a, t_strdouble *b)
{
	int16_t	sign;

	if (a->is_negative != b->is_negative)
	{
		if (b->is_negative)
			return (1);
		return (-1);
	}
	sign = 1;
	if (a->is_negative)
		sign = -1;
	if (a->power > b->power)
		return (1 * sign);
	if (a->power < b->power)
		return (-1 * sign);
	return (ft_strcmp(a->number, b->number) * sign);
}

int16_t	ft_compare_abs_sd(t_strdouble *a, t_strdouble *b)
{
	if (a->power > b->power)
		return (1);
	if (a->power < b->power)
		return (-1);
	return (ft_strcmp(a->number, b->number));
}

uint64_t	ft_newnum_len_basic(t_strdouble *a, t_strdouble *b)
{
	t_strdouble	*buff;
	uint64_t	max_len;

	if (ft_compare_abs_sd(a, b) < 0)
	{
		buff = b;
		b = a;
		a = buff;
	}
	if (a->num_len > b->num_len)
		max_len = a->num_len;
	else
		max_len = b->num_len;
	return (max_len + a->power - b->power);
}
