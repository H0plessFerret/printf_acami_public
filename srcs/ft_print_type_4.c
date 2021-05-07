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
