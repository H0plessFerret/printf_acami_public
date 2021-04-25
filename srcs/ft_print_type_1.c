/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:10:23 by acami             #+#    #+#             */
/*   Updated: 2021/04/25 15:37:57 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_print_type.h"
#include "../libft/libft.h"

int	ft_print_char(void *elem, t_mask *mask)
{
	(void)mask;
	return (write(1, *(int *)(elem), 1));
}

int	ft_print_string(void *elem, t_mask *mask)
{
	char	*str;

	str = (char *)elem;
	(void)mask;
	return (write(1, str, ft_strlen(str)));
}

static void	ft_strrev(char *str, size_t len)
{
	size_t	count;
	char	buff;

	count = 0;
	if (len == 0)
		len = ft_strlen(str);
	while (count < len / 2)
	{
		buff = *(str + len - count - 1);
		*(str + len - count - 1) = *(str + count);
		*(str + count) = buff;
		++count;
	}
}

int	ft_put_unsignednbr_base(size_t nbr, char *base, t_mask *mask)
{
	size_t	count;
	size_t	divider;
	char	res[65];

	count = 0;
	divider = ft_strlen(base);
	if ((nbr == 0) && (mask->prescision != 0))
		return (write(1, "0", 1));
	while (nbr != 0)
	{
		*(res + count) = *(base + (nbr % divider));
		nbr = (nbr / divider);
		++count;
	}
	*(res + count) = '\0';
	ft_strrev(res, count);
	return (write(1, res, count));
}

int	ft_put_abs_nbr_base(int64_t nbr, char *base, t_mask *mask)
{
	size_t	count;
	int		divider;
	char	res[65];

	count = 0;
	divider = ft_strlen(base);
	if (nbr > 0)
		nbr = nbr * -1;
	if ((nbr == 0) && (mask->prescision != 0))
		write(1, "0", 1);
	while (nbr != 0)
	{
		*(res + count) = *(base - (nbr % divider));
		nbr = (nbr / divider);
		++count;
	}
	*(res + count) = '\0';
	ft_strrev(res, count);
	return (write(1, res, count));
}
