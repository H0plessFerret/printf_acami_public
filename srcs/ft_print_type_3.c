/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:28:16 by acami             #+#    #+#             */
/*   Updated: 2021/04/29 00:28:16 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_print_type.h"
#include "../libft/libft.h"

char	*ft_put_unsignedfloat_base(long double nbr, int8_t base, t_mask *mask)
{
	int8_t		nbr_power;
	char		*buff;

	buff = NULL;
	nbr_power = ft_find_power(nbr, base);
	if (mask->specifier == 'f' || mask->specifier == 'F')
		buff = ft_put_float_normal_base(nbr, base, mask, nbr_power);
	if (mask->specifier == 'e' || mask->specifier == 'E')
		buff = ft_put_float_scientific_base(nbr, base, mask, nbr_power);
	if (mask->specifier == 'g' || mask->specifier == 'G')
		buff = ft_put_float_g_base(nbr, base, mask, nbr_power);
	if (mask->uppercase)
		ft_strtoupper(buff);
	return (buff);
}

char	*ft_put_float_normal_base(long double nbr, int8_t base, t_mask *mask,
int8_t nbr_power)
{
	int8_t		integer_part;
	size_t		curr_elem;
	const char	*base_symbols;
	char		*buffer;
	static char	res[DLENGTH_MAX];

	curr_elem = 0;
	base_symbols = "0123456789abcdef";
	if (nbr_power > 0)
		ft_norm_float_base(&nbr, &nbr_power, base);
	while (nbr_power >= 0 || curr_elem == 0)
	{
		integer_part = (int8_t)nbr;
		res[curr_elem++] = base_symbols[integer_part];
		nbr = (nbr - integer_part) * base;
		--nbr_power;
	}
	res[curr_elem] = '\0';
	if (mask->prescision != 0 || mask->alternative_mode == true)
	{
		buffer = ft_put_fraction_base(nbr, base, mask);
		ft_strlcat(res, buffer, DLENGTH_MAX);
	}
	return (res);
}

char	*ft_put_fraction_base(long double nbr, int8_t base, t_mask *mask)
{
	int8_t		current_digit;
	size_t		count;
	const char	*base_symbols;
	static char	res[DLENGTH_MAX];

	res[0] = '.';
	count = 1;
	base_symbols = "0123456789abcdef";
	while (count <= (size_t)(mask->prescision) && count < DLENGTH_MAX - 1)
	{
		current_digit = (int8_t)nbr;
		res[count] = base_symbols[current_digit];
		nbr = (nbr - current_digit) * base;
		++count;
	}
	res[count] = '\0';
	return (res);
}
