/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:32:51 by acami             #+#    #+#             */
/*   Updated: 2021/04/28 16:03:38 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_print_type.h"

int	ft_elem_write(char *str, size_t str_len, t_mask *mask)
{
	int8_t	symbols_for_sign;
	bool	space_was_inserted;
	int		count;
	char	sign;

	count = 0;
	symbols_for_sign = mask->print_sign;
	space_was_inserted = false;
	if (mask->specifier == 'p')
		symbols_for_sign = 2;
	if (mask->left_justified == false && mask->zero_padding == false
		&& mask->width != NOT_SET)
		while ((str_len + symbols_for_sign + count) < (size_t)(mask->width))
		{
			space_was_inserted = true;
			count += write(1, " ", 1);
		}
	if (mask->print_sign == true)
	{
		sign = "+-"[mask->is_negative];
		if (mask->specifier == 'p')
			count += write(1, "0x", 2);
		else
			count += write(1, &sign, 1);
	}
	else if (mask->free_space == true && space_was_inserted == false)
		count += write(1, " ", 1);
	if (mask->zero_padding == true)
		while ((str_len + count) < (size_t)(mask->width))
			count += write(1, "0", 1);
	count += write(1, str, str_len);
	if (mask->left_justified == true)
		while (count < mask->width)
			count += write(1, " ", 1);
	return (count);
}
