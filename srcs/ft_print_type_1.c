/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:10:23 by acami             #+#    #+#             */
/*   Updated: 2021/04/28 16:12:41 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_print_type.h"
#include "../headers/ft_pull_type.h"
#include "../libft/libft.h"

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

char	*ft_put_unsignednbr_base(uintmax_t nbr, int8_t base, t_mask *mask)
{
	static const char	*base_symbols;
	size_t				count;
	static char			res[65];

	count = 0;
	base_symbols = "0123456789abcdef";
	if ((nbr == 0) && (mask->prescision != 0))
		write(1, "0", 1);
	while (nbr != 0)
	{
		res[count] = base_symbols[nbr % base];
		nbr = (nbr / base);
		++count;
	}
	res[count] = '\0';
	ft_strrev(res, count);
	if (mask->uppercase)
		ft_strtoupper(res);
	return (res);
}

int	ft_print_signed(va_list *arg_list, t_mask *mask)
{
	intmax_t	num;
	char		*buff;
	
	num = ft_pull_signed(arg_list, &(mask->length_modifiers));
	if (num < 0)
	{
		mask->is_negative = true;
		mask->print_sign = true;
		buff = ft_put_unsignednbr_base((uintmax_t)(num * -1), 10, mask);
	}
	else
		buff = ft_put_unsignednbr_base((uintmax_t)num, 10, mask);
	return (ft_elem_write(buff, ft_strlen(buff), mask));
}

int	ft_print_unsigned(va_list *arg_list, t_mask *mask)
{
	uintmax_t	num;
	int			base;
	char		*buff;

	num = ft_pull_unsigned(arg_list, &(mask->length_modifiers));
	base = 10;
	if (mask->specifier == 'o')
		base = 8;
	else if (mask->specifier == 'x' || mask->specifier == 'X')
		base = 16;
	buff = ft_put_unsignednbr_base(num, base, mask);
	return (ft_elem_write(buff, ft_strlen(buff), mask));
}

int	ft_print_percent(va_list *arg_list, t_mask *mask)
{
	(void)arg_list;
	return (ft_elem_write("%", 1, mask));
}

int	ft_print_char(va_list *arg_list, t_mask *mask)
{
	char	c[2];

	c[0] = ft_pull_char(arg_list, &(mask->length_modifiers));
	c[1] = '\0';
	return (ft_elem_write(c, 1, mask));
}

int	ft_print_string(va_list *arg_list, t_mask *mask)
{
	char	*str;

	str = ft_pull_pointer(arg_list, &(mask->length_modifiers));
	if (str == NULL)
	{
		if (mask->prescision > 5)
			str = "(null)";
		else
			str = "";
	}
	else if (mask->prescision != NOT_SET)
		return (ft_elem_write(str, mask->prescision, mask));
	return (ft_elem_write(str, ft_strlen(str), mask));
}

int	ft_print_pointer(va_list *arg_list, t_mask *mask)
{
	void	*ptr;
	char	*str;

	ptr = ft_pull_pointer(arg_list, &(mask->length_modifiers));
	if (ptr == NULL)
		str = "(null)";
	else
		str = ft_put_unsignednbr_base((uintmax_t)ptr, 16, mask);
	return (ft_elem_write(str, ft_strlen(str), mask));
}

int	ft_save_counter(va_list *arg_list, t_mask *mask)
{
	intmax_t	*to_write;

	to_write = ft_pull_pointer(arg_list, &(mask->length_modifiers));
	*to_write = (intmax_t)mask->symbols_printed;
	return (0);
}

int	ft_print_float(va_list *arg_list, t_mask *mask)
{
	(void)arg_list;
	(void)mask;
	return (0);
}

/*
static int8_t	ft_unify_double(long double *nbr, int8_t base)
{
	int8_t	nbr_power;

	nbr_power = 0;
	while (*nbr > base)
	{
		*nbr /= base;
		++nbr_power;
	}
	while (*nbr < 1)
	{
		*nbr *= base;
		--nbr_power;
	}
	return (nbr_power);
}

char	*ft_put_float_scientific_base(long double nbr, int8_t base, t_mask *mask,
int8_t nbr_power);

char	*ft_put_float_normal_base(long double nbr, int8_t base, t_mask *mask,
int8_t nbr_power)
{
	int8_t		integer_part;
	size_t		curr_elem;
	size_t		count;
	static char	*base_symbols;
	static char	res[8192];

	curr_elem = 0;
	base_symbols = "0123456789abcdef";
	while (nbr_power > 0)
	{
		integer_part = (int8_t)nbr;
		res[curr_elem] = base_symbols[integer_part];
		nbr = (nbr - integer_part) * base;
		--nbr_power;
		++curr_elem;
	}
	if (mask->prescision != 0)
	{
		res[curr_elem] = '.';
		++curr_elem;
		count = 0;
		while (count < mask->prescision)
		{
			integer_part = (int8_t)nbr;
			res[curr_elem] = base_symbols[integer_part];
			nbr = (nbr - integer_part) * base;
			--nbr_power;
			++curr_elem;
		}
	}
	res[curr_elem] = '\0';
	return (res);
}

char	*ft_put_unsignedfloat_base(long double nbr, int8_t base, t_mask *mask)
{
	size_t		count;
	int8_t		nbr_power;
	static char	res[512];
	char		*buff;
	char		*buff_sci;

	count = 0;
	nbr_power = ft_unify_double(&nbr, base);
	if (mask->specifier == 'e' || mask->specifier == 'E'
			|| mask->specifier == 'g' || mask->specifier == 'G')
		buff_sci = ft_put_float_scientific_base(nbr, base, mask, nbr_power);
	if (mask->specifier != 'e' && mask->specifier != 'E')
		buff = ft_put_float_normal_base(nbr, base, mask, nbr_power);
	if (mask->uppercase)
		ft_toupper(res);
	if (mask->specifier == 'g' || mask->specifier == 'G')
	{
		if (ft_strlen(buff) > ft_strlen(buff_sci))
			return (buff_sci);
		return (buff);
	}
		
	return (res);
}



// TO DO
int	ft_print_float(va_list *arg_list, t_mask *mask)
{
	long double	num;
	int			base;
	char		*buff;

	num = ft_pull_float(arg_list, &(mask->length_modifiers));
	base = 10;
	return (ft_elem_write(buff, ft_strlen(buff), mask));
}
*/