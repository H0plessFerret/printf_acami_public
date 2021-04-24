/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_bonus_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:32:19 by acami             #+#    #+#             */
/*   Updated: 2021/04/24 15:35:22 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_print_type.h"

extern int	g_prescision;

int	ft_print_oct(void *elem)
{
	return (ft_put_unsignednbr_base(*(unsigned int *)elem, "01234567"));
}

static int	ft_print_mantis(double f_elem)
{
	int		curr_pos;
	int		count;
	int64_t	num;
	char	buff;

	count = 0;
	curr_pos = 0;
	while (curr_pos < g_prescision)
	{
		f_elem *= 10;
		num = (int64_t)f_elem;
		f_elem -= num;
		buff = (char)(num * -1) + '0';
		count += write(1, &buff, 1);
		++curr_pos;
	}
	return (count);
}

int	ft_print_abs_float(void *elem)
{
	double	f_elem;
	int64_t	num;
	int		count;

	count = 0;
	f_elem = *(double *)elem;
	if (f_elem > 0)
		f_elem *= -1;
	num = (int64_t)f_elem;
	if (num == 0)
		count += write(1, "0", 1);
	count += ft_print_abs_int((void *)(&num));
	if (g_prescision != 0)
		count += write(1, ".", 1);
	f_elem -= num;
	count += ft_print_mantis(f_elem);
	return (count);
}

int	ft_print_scientific(void *elem);

int	ft_print_e_f(void *elem);

int	ft_print_hex_float(void *elem)
{
	(void)elem;
	return (0);
}

int	ft_save_printed(void *elem, int saved)
{
	*(int *)elem = saved;
	return (0);
}
