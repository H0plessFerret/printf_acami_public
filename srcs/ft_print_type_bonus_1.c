/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_bonus_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:32:19 by acami             #+#    #+#             */
/*   Updated: 2021/04/23 17:04:17 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_print_type.h"
#include "../libft/libft.h"

int	ft_print_oct(void *elem, int prescision)
{
	(void)prescision;
	return (ft_put_unsignednbr_base(*(unsigned int *)elem, "01234567"));
}

int	ft_print_float(void *elem, int prescision)
{
	
}

int	ft_print_scientific(void *elem, int prescision);

int	ft_print_e_f(void *elem, int prescision);

int	ft_print_hex_float(void *elem, int prescision);

int	ft_save_printed(void *elem, int prescision);
