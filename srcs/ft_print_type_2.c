/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:01:19 by acami             #+#    #+#             */
/*   Updated: 2021/04/25 18:43:04 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_print_type.h"

int	ft_print_pointer(void *elem, t_mask *mask)
{
	if (elem == NULL)
		return (write(1, "(null)", 6));
	write(1, "0x", 2);
	return (2 + ft_put_unsignednbr_base((unsigned long long)elem,
			"0123456789abcdef", mask));
}

int	ft_print_abs_int(void *elem, t_mask *mask)
{
	return (ft_put_abs_nbr_base(*(long long *)elem, "0123456789", mask));
}

int	ft_print_uint(void *elem, t_mask *mask)
{
	return (ft_put_unsignednbr_base(*(unsigned long long *)elem,
			"0123456789", mask));
}

int	ft_print_hex(void *elem, t_mask *mask)
{
	return (ft_put_unsignednbr_base(*(unsigned long long *)elem,
			"0123456789abcdef", mask));
}

int	ft_print_hex_upper(void *elem, t_mask *mask)
{
	return (ft_put_unsignednbr_base(*(unsigned long long *)elem,
			"0123456789ABCDEF", mask));
}
