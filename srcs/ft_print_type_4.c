/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 23:35:22 by acami             #+#    #+#             */
/*   Updated: 2021/05/07 23:35:22 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_print_type.h"
#include "../libft/libft.h"

char	*ft_put_float_scientific_base(long double nbr, int8_t base, t_mask *mask,
int8_t nbr_power)
{
	static char	res[DLENGTH_MAX];
	char		*buff;
	int8_t		curr_elem;

	ft_norm_float_base(&nbr, &nbr_power, base);
	buff = ft_put_float_normal_base(nbr, base, mask, 0);
	curr_elem = ft_strlen(buff);
	ft_strlcpy(res, buff, DLENGTH_MAX);
	res[curr_elem++] = 'e';
	if (nbr_power < 0)
	{
		res[curr_elem++] = '-';
		nbr_power *= -1;
	}
	else
		res[curr_elem++] = '+';
	buff = ft_put_unsignednbr_base(nbr_power, BASE_DECIMAL, mask);
	if (ft_strlen(buff) < 2)
		res[curr_elem++] = '0';
	res[curr_elem] = '\0';
	ft_strlcat(res, buff, DLENGTH_MAX);
	return (res);
}

static void	ft_trim_insignificant_digits(char *number)
{
	size_t	insignificant_len;
	size_t	count;
	size_t	insignificant_pos;

	count = 0;
	while (number[count] != '.')
	{
		if (number[count] == '\0')
			return ;
		++count;
	}
	insignificant_len = 1;
	insignificant_pos = count;
	++count;
	while (number[count] != '\0' && number[count] != 'e')
	{
		if (insignificant_len != 0)
		{
			if (number[count] == '0')
				++insignificant_len;
			else
				insignificant_len = 0;
		}
		else
		{
			if (number[count] == '0')
			{
				++insignificant_len;
				insignificant_pos = count;
			}
		}
		++count;
	}
	ft_memmove(number + insignificant_pos, number + insignificant_pos + insignificant_len, 7);
}

char	*ft_put_float_g_base(long double nbr, int8_t base, t_mask *mask,
int8_t nbr_power)
{
	char	*buff;
	if (nbr_power < -4 || nbr_power >= mask->prescision)
	{
		if (mask->prescision > 1)
			--(mask->prescision);
		buff = ft_put_float_scientific_base(nbr, base, mask, nbr_power);
		ft_trim_insignificant_digits(buff);
		return (buff);
	}
	mask->prescision = mask->prescision - nbr_power;
	buff = ft_put_float_normal_base(nbr, base, mask, nbr_power);
	ft_trim_insignificant_digits(buff);
	return (buff);
}
