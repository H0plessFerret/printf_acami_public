/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:06:19 by acami             #+#    #+#             */
/*   Updated: 2021/04/25 18:49:49 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_print_type.h"

int	ft_print_percent_sign(void *elem, t_mask *mask)
{
	(void)mask;
	return (write(1, "%", 1));
}

int	ft_print_char_n_times(char sym, int amount_of_times)
{
	int	count;

	count = 0;
	while (count < amount_of_times && write(1, &sym, 1))
		++count;
	return (count);
}
