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
	t_mask	mask;
	int		count;

	count = 0;
	va_start(arg_list, format_spec);
	count += ft_print_till_percent(&format_spec);
	while (*format_spec != '\0')
	{
		ft_generate_mask(&format_spec, &mask);
		if (mask.mask == 0)
			++count;
		else
		{
			count += ft_print_by_arg(&arg_list, &mask,
					ft_find_corresponding_print(&mask));
		}
		count += ft_print_till_percent(&format_spec);
	}
	va_end(arg_list);
	return (count);
}
