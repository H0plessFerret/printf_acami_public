/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pull_type_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:52:24 by acami             #+#    #+#             */
/*   Updated: 2021/04/27 15:53:08 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_pull_type.h"

void	*ft_pull_pointer(va_list *arg_list, t_length *length_modifiers)
{
	return (va_arg(*arg_list, void *));
}

intmax_t	*ft_pull_counter(va_list *arg_list, t_length *length_modifiers)
{
	return (va_arg(*arg_list, intmax_t *));
}
