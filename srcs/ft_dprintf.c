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
	t_mask	mask;
	int		count;

	count = 0;
	va_start(arg_list, format_spec);
	count += ft_print_till_percent(&format_spec);
	while (*format_spec != '\0')
	{
		ft_generate_mask(&format_spec, &mask, arg_list);
		if (mask.specifier == NOT_SET)
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
