/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_by_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 19:15:25 by acami             #+#    #+#             */
/*   Updated: 2021/04/23 19:24:44 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../headers/ft_print_type.h"

extern int	g_width;
extern int	g_prescision;

static int	ft_print_suffix(void *data, uint32_t mask);
static int	ft_print_postfix(void *data, uint32_t mask);

int	ft_print_by_arg(void *data, uint32_t mask, int (*func)(void *data,
int prescision))
{
	int	count;

	count = 0;
	count += ft_print_suffix(data, mask);
	count += (*func)(data, g_prescision);
	count += ft_print_postfix(data, mask);
	return (count);
}
