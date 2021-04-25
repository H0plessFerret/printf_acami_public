/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_info_from_arglist.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:18:48 by acami             #+#    #+#             */
/*   Updated: 2021/04/25 19:06:09 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static void	ft_set_width_prescision(va_list *arg_list, t_mask *mask)
{
	if ((mask->mask & SPEC_ASTERISK) != 0)
	{
		mask->width = va_arg(*arg_list, int);
		if (mask->width < 0)
			mask->width = 1;
	}
	if ((mask->mask & SPEC_DOTASTERISK) != 0)
	{
		mask->prescision = va_arg(*arg_list, int);
		if (mask->prescision < 0 && (mask->mask & SPEC_IS_FLOAT) != 0)
			mask->prescision = 6;
		else if (mask->prescision < 0)
			mask->prescision = 0;
	}
}

void	*ft_extract_info_from_arglist(va_list *arg_list, t_mask *mask, void *data)
{
	ft_set_width_prescision(arg_list, mask);
	if ((mask->mask & SPEC_C) != 0)
		*(char *)data = (char)va_arg(*arg_list, int);
	else if ((mask->mask & SPEC_S) != 0)
		*(char **)data = va_arg(*arg_list, char *);
	else if ((mask->mask & SPEC_P) != 0)
		*(void **)data = va_arg(*arg_list, void *);
	else if ((mask->mask & SPEC_D_I) != 0)
		*(int *)data = va_arg(*arg_list, int);
	else if ((mask->mask & SPEC_IS_UNSIGNED) != 0)
		*(unsigned int *)data = va_arg(*arg_list, unsigned int);
	else if ((mask->mask & SPEC_IS_FLOAT) != 0)
		*(double *)data = va_arg(*arg_list, double);
	else if ((mask->mask & SPEC_N) != 0)
		*(int **)data = va_arg(*arg_list, int *);
	return (data);
}
