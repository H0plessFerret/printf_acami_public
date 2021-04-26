/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:11:36 by acami             #+#    #+#             */
/*   Updated: 2021/04/25 16:41:18 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../headers/ft_print_type.h"


int	ft_printf(const char *format_spec, ...)
{
	va_list	arg_list;
	int		count;

	va_start(arg_list, format_spec);
	count = ft_vprintf(format_spec, arg_list);
	va_end(arg_list);
	return (count);
}

int	ft_vprintf(const char *format_spec, va_list arg_list)
{
	return (ft_vdprintf(1, format_spec, arg_list));
}
