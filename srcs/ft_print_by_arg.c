/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_by_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 19:15:25 by acami             #+#    #+#             */
/*   Updated: 2021/04/24 16:01:00 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../headers/ft_print_type.h"

extern int	g_width;
extern int	g_prescision;

// prints prefix to the actual data
int	ft_print_prefix(uint32_t mask, char	sign);

// prints postfix to the actual data
int	ft_print_postfix(uint32_t mask, int printed_already);

int	ft_print_by_arg(va_list arg_list, uint32_t mask, int (*func)(void *data))
{
	int		count;
	char	sign;
	void	*data;

	count = 0;
	data = ft_extract_info_from_arglist(arg_list, mask);
	return (count);
}
