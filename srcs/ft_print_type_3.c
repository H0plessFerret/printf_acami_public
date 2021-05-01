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

static char	*ft_put_mantis_base(long double nbr, int8_t base, t_mask *mask)
{
	int8_t		current_digit;
	size_t		count;
	const char	*base_symbols;
	static char	res[4940];

	res[0] = '.';
	count = 1;
	base_symbols = "0123456789abcdef";
	while (count < (size_t)(mask->prescision))
	{
		current_digit = (int8_t)nbr;
		res[count] = base_symbols[current_digit];
		nbr = (nbr - current_digit) * base;
		++count;
	}
	res[count] = '\0';
	return (res);
}

static char	*ft_put_float_normal_base(long double nbr, int8_t base, t_mask *mask,
int8_t nbr_power)
{
	int8_t		integer_part;
	size_t		curr_elem;
	const char	*base_symbols;
	char		*buffer;
	static char	res[4940];

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
		buffer = ft_put_mantis_base(nbr, base, mask);
		ft_strlcat(res, buffer, 4940);
	}
	return (res);
}

static char	*ft_put_float_scientific_base(long double nbr, int8_t base, t_mask *mask,
int8_t nbr_power)
{
	/*
	static char	res[8192];
	char		*buff;
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
	count = ft_strlen(buff);
	ft_strlcpy(res, buff, count + 1);
	res[count] = 'e';
	res[count + 1] = '\0';
	*/
	(void)nbr;
	(void)nbr_power;
	(void)mask;
	(void)base;
	return (NULL);
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

int	ft_print_float(va_list *arg_list, t_mask *mask)
{
	long double	num;
	int			base;
	char		*buff;

	base = 10;
	if (mask->prescision == NOT_SET)
		mask->prescision = 6;
	num = ft_pull_float(arg_list, &(mask->length_modifiers));
	if (num < 0)
	{
		mask->is_negative = true;
		mask->print_sign = true;
		buff = ft_put_unsignedfloat_base(num * -1, base, mask);
	}
	else
		buff = ft_put_unsignedfloat_base(num, base, mask);
	return (ft_elem_write(buff, ft_strlen(buff), mask));
}
