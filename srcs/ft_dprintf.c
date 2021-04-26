/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 20:45:03 by acami             #+#    #+#             */
/*   Updated: 2021/04/26 20:45:03 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dprintf(int fd, const char *format_spec, ...)
{
	va_list	arg_list;
	int		count;

	va_start(arg_list, format_spec);
	count = ft_vdprintf(fd, format_spec, arg_list);
	va_end(arg_list);
	return (count);
}

int	ft_vdprintf(int fd, const char *format_spec, va_list arg_list)
{
	t_mask		mask;
	int			count;
	t_print_fn	print_fn;

	count = 0;
	count += ft_dprint_till_percent(fd, &format_spec);
	while (*format_spec != '\0')
	{
		ft_generate_mask(&format_spec, &mask, arg_list);
		if (mask.specifier == NOT_SET)
			++count;
		else
		{
			mask.symbols_printed = count;
			print_fn = ft_find_corresponding_print(&mask);
			if (print_fn != NULL)
				count += (*print_fn)(&arg_list, &mask);
		}
		count += ft_print_till_percent(&format_spec);
	}
	return (count);
}
