/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_by_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 19:15:25 by acami             #+#    #+#             */
/*   Updated: 2021/04/25 18:51:13 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../headers/ft_print_type.h"

static int	ft_len_unsignednbr_base(unsigned long long int nbr, char *base,
t_mask *mask)
{
	size_t					count;
	unsigned long long int	divider;

	count = 0;
	divider = ft_strlen(base);
	if ((nbr == 0) && (mask->prescision != 0))
		return (1);
	while (nbr != 0)
	{
		nbr = (nbr / divider);
		++count;
	}
	return (count);
}

static int	ft_len_abs_nbr_base(long long int nbr, char *base, t_mask *mask)
{
	size_t			count;
	long long int	divider;

	count = 0;
	divider = ft_strlen(base);
	if (nbr > 0)
		nbr = nbr * -1;
	if ((nbr == 0) && (mask->prescision != 0))
		write(1, "0", 1);
	while (nbr != 0)
	{
		nbr = (nbr / divider);
		++count;
	}
	return (count);
}

int	ft_print_prefix(t_mask *mask, void *data, char sign);

int	ft_print_by_arg(va_list *arg_list, t_mask *mask, int (*func)(void *data,
t_mask *mask))
{
	int		count;
	char	sign;
	void	*data;

	count = 0;
	data = ft_extract_info_from_arglist(arg_list, mask);
	if (data == NULL)
		return (0);
	sign = '+';
	if (*(long long int *)data < 0)
		sign = '-';
	count += ft_print_prefix(mask, data, sign);
	count += (*func)(data, mask);
	if ((mask->mask & SPEC_MINUS) != 0)
		count += ft_print_char_n_times(' ', mask->width - count);
	free(data);
	return (count);
}
