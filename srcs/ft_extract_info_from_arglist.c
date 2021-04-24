/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_info_from_arglist.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:18:48 by acami             #+#    #+#             */
/*   Updated: 2021/04/24 18:03:23 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

extern int	g_width;
extern int	g_prescision;

static void	ft_set_width_prescision(va_list arg_list, uint32_t mask)
{
	if ((mask & SPEC_ASTERISK) != 0)
	{
		g_width = va_arg(arg_list, int);
		if (g_width < 0)
			g_width = 1;
	}
	if ((mask & SPEC_DOTASTERISK) != 0)
	{
		g_prescision = va_arg(arg_list, int);
		if (g_prescision < 0 && (mask & SPEC_IS_FLOAT) != 0)
			g_prescision = 6;
		else if (g_prescision < 0)
			g_prescision = 0;
	}
}

static void	*ft_pull_arg_from_arglist(va_list arg_list, uint32_t mask)
{
	int		*buff;

	if (mask & SPEC_D_I)
	{
		buff = (int *)malloc(sizeof(int));
		*buff = va_arg(arg_list, int);
		return (void *)buff;
	}

	return (NULL);
}

void	*ft_extract_info_from_arglist(va_list arg_list, uint32_t mask)
{
	void	*data;

	ft_set_width_prescision(arg_list, mask);
	data = ft_pull_arg_from_arglist(arg_list, mask);
	return (data);
}
