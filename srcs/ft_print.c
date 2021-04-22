/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:11:36 by acami             #+#    #+#             */
/*   Updated: 2021/04/22 13:34:38 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../headers/ft_print_type.h"

int	ft_printf(const char *format_spec, ...)
{
	va_list		arg_list;
	uint32_t	mask;
	int			extra_flag;
	int			count;

	count = 0;
	va_start(arg_list, format_spec);
	count += ft_print_till_percent(&format_spec);
	while (*format_spec != '\0')
	{
		mask = ft_generate_mask(ft_isolate_specifiers(&format_spec),
				&extra_flag);
		count += ft_print_arg(arg_list, mask,
				ft_find_corresponding_print(mask), extra_flag);
		count += ft_print_till_percent(&format_spec);
	}
	va_end(arg_list);
	return (count);
}
