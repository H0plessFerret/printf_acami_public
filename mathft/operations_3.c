/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:53:57 by acami             #+#    #+#             */
/*   Updated: 2021/05/17 17:27:12 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathft.h"

int16_t	ft_add_digits(t_strdouble *a, t_strdouble *b, int64_t curr_power,
int16_t *carry_over)
{
	int16_t	a_elem;
	int16_t	b_elem;
	int16_t	curr_elem;

	if ((a->last_sig_digit <= curr_power) && (curr_power < a->power + 1))
		a_elem = a->number[a->power - curr_power] - '0';
	else
		a_elem = 0;
	if ((b->last_sig_digit <= curr_power) && (curr_power < b->power + 1))
		b_elem = b->number[b->power - curr_power] - '0';
	else
		b_elem = 0;
	curr_elem = a_elem + b_elem + *carry_over;
	if (curr_elem >= 10)
	{
		*carry_over = 1;
		curr_elem -= 10;
	}
	else
		*carry_over = 0;
	return (curr_elem);
}
