/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_bonus_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:32:19 by acami             #+#    #+#             */
/*   Updated: 2021/04/23 21:10:17 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_print_type.h"
#include "../libft/libft.h"

int	ft_print_oct(void *elem, int prescision)
{
	(void)prescision;
	return (ft_put_unsignednbr_base(*(unsigned int *)elem, "01234567"));
}

int	ft_print_abs_float(void *elem, int prescision)
{
	double	f_elem;
	int64_t	num;
	int		count;
	int		curr_pos;
	char	buff;

	f_elem = *(double *)elem;
	if (f_elem > 0)
		f_elem *= -1;
	num = (int64_t)f_elem;
	count += ft_print_abs_int((void *)(&num), 0);
	if (prescision != 0)
		count += write(1, ".", 1);
	curr_pos = 0;
	f_elem -= num;
	while (curr_pos < prescision)
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

int	ft_print_scientific(void *elem, int prescision);

int	ft_print_e_f(void *elem, int prescision);

int	ft_print_hex_float(void *elem, int prescision)
{
	(void)elem;
	(void)prescision;
	return (0);
}

int	ft_save_printed(void *elem, int saved)
{
	*(int *)elem = saved;
	return (0);
}
