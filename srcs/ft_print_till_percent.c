/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_till_percent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:55:52 by acami             #+#    #+#             */
/*   Updated: 2021/05/21 23:34:21 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_print_till_percent(t_cbuffer *cbuffer, const char **format_spec)
{
	int	count;
	int	symbols_printed;

	count = 0;
	symbols_printed = 0;
	while (*(*format_spec + count) != '\0'
		&& *(*format_spec + count) != '%')
		++count;
	symbols_printed += ft_insert_cbuffer(cbuffer, *format_spec, count);
	*format_spec += count;
	return (symbols_printed);
}
