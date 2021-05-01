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
#include "../headers/ft_pull_type.h"
#include "../libft/libft.h"

static int8_t	ft_norm_down_float(long double *nbr, int8_t base)
{
	int8_t	nbr_power;

	nbr_power = 0;
	// It's pretty slow actually, if we could divide by pow(base, 5) for example
	// it would make the process 5 times faster
	while (*nbr > base)
	{
		*nbr /= base;
		++nbr_power;
	}
	return (nbr_power);
}

static char	*ft_put_fraction_base(long double nbr, int8_t base, t_mask *mask)
{
	int8_t		current_digit;
	size_t		count;
	const char	*base_symbols;
	static char	res[DLENGTH_MAX];

	res[0] = '.';
	count = 1;
	base_symbols = "0123456789abcdef";
	while (count <= (size_t)(mask->prescision))
	{
		current_digit = (int8_t)nbr;
		res[count] = base_symbols[current_digit];
		nbr = (nbr - current_digit) * base;
		++count;
	}
	res[count] = '\0';
	return (res);
}

static char	*ft_put_float_normal_base(long double nbr, int8_t base,
t_mask *mask, int8_t nbr_power)
{
	int8_t		integer_part;
	size_t		curr_elem;
	const char	*base_symbols;
	char		*buffer;
	static char	res[DLENGTH_MAX];

	curr_elem = 0;
	base_symbols = "0123456789abcdef";
	while (nbr_power >= 0)
	{
		integer_part = (int8_t)nbr;
		res[curr_elem] = base_symbols[integer_part];
		nbr = (nbr - integer_part) * base;
		--nbr_power;
		++curr_elem;
	}
	res[curr_elem] = '\0';
	if (mask->prescision != 0)
	{
		buffer = ft_put_fraction_base(nbr, base, mask);
		ft_strlcat(res, buffer, DLENGTH_MAX);
	}
	return (res);
}

static char	*ft_put_float_scientific_base(long double nbr, int8_t base,
t_mask *mask, int8_t nbr_power)
{
	static char	res[DLENGTH_MAX];
	char		*buff;
	int8_t		curr_elem;
	int8_t		count;

	if (nbr_power == 0)
	{
		while (nbr < 1)
		{
			nbr *= base;
			--nbr_power;
		}
	}
	buff = ft_put_float_normal_base(nbr, base, mask, 0);
	curr_elem = ft_strlen(buff);
	ft_strlcpy(res, buff, DLENGTH_MAX);
	res[curr_elem] = 'e';
	if (nbr_power < 0)
		res[curr_elem + 1] = '-';
	else
		res[curr_elem + 1] = '+';
	curr_elem += 2;
	buff = ft_put_unsignednbr_base(nbr_power, BASE_DECIMAL, mask);
	count = 3 - ft_strlen(buff);
	while (count > 0)
	{
		res[curr_elem] = '0';
		++curr_elem;
		--count;
	}
	res[curr_elem] = '\0';
	ft_strlcat(res, buff, DLENGTH_MAX);
	return (res);
}

char	*ft_put_unsignedfloat_base(long double nbr, int8_t base, t_mask *mask)
{
	int8_t		nbr_power;
	char		*buff;
	char		*buff_sci;

	buff = NULL;
	buff_sci = NULL;
	nbr_power = ft_norm_down_float(&nbr, base);
	if (mask->specifier != 'f' && mask->specifier != 'F')
		buff_sci = ft_put_float_scientific_base(nbr, base, mask, nbr_power);
	if (mask->specifier != 'e' && mask->specifier != 'E')
		buff = ft_put_float_normal_base(nbr, base, mask, nbr_power);
	if (mask->specifier == 'g' || mask->specifier == 'G')
	{
		if (ft_strlen(buff_sci) < ft_strlen(buff))
			buff = buff_sci;
	}
	if (buff != NULL)
		return (buff);
	return (buff_sci);
}
