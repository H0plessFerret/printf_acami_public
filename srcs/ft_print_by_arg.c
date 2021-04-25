/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_by_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 19:15:25 by acami             #+#    #+#             */
/*   Updated: 2021/04/25 16:45:25 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../headers/ft_print_type.h"

// prints prefix to the actual data
int	ft_print_prefix(t_mask *mask, char	sign);

// prints postfix to the actual data
int	ft_print_postfix(t_mask *mask, int printed_already);

int	ft_print_by_arg(va_list *arg_list, t_mask *mask, int (*func)(void *data,
t_mask *mask))
{
	int		count;
	char	sign;
	void	*data;

	count = 0;
	data = ft_extract_info_from_arglist(arg_list, mask);
	return (count);
}
