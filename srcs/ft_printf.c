/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:11:36 by acami             #+#    #+#             */
/*   Updated: 2021/05/15 17:34:25 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../headers/ft_print_type.h"

int	ft_printf(const char *format_spec, ...)
{
	va_list	arg_list;
	int		count;

	va_start(arg_list, format_spec);
	count = ft_vprintf(format_spec, &arg_list);
	va_end(arg_list);
	return (count);
}

int	ft_vprintf(const char *format_spec, va_list *arg_list)
{
	t_mask		mask;
	int			count;
	t_print_fn	print_fn;

	count = 0;
	count += ft_print_till_percent(1, &format_spec);
	while (*format_spec != '\0')
	{
		ft_generate_mask(&format_spec, &mask, arg_list);
		if (mask.specifier == NOT_SET)
		{
			count += ft_elem_write("%", 1, &mask);
			++format_spec;
		}
		else
		{
			mask.symbols_printed = count;
			print_fn = ft_find_corresponding_print(&mask);
			if (print_fn != NULL)
				count += (*print_fn)(arg_list, &mask);
		}
		count += ft_print_till_percent(1, &format_spec);
	}
	return (count);
}
