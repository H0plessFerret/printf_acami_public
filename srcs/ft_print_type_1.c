/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:10:23 by acami             #+#    #+#             */
/*   Updated: 2021/04/28 17:39:54 by acami            ###   ########.fr       */
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
	const char	*base_symbols;
	size_t		count;
	static char	res[65];

	count = 0;
	base_symbols = "0123456789abcdef";
	if ((nbr == 0) && (mask->prescision != 0))
	{
		res[count] = '0';
		++count;
	}
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
	mask->alternative_mode = false;
	if (mask->prescision != NOT_SET || mask->left_justified)
		mask->zero_padding = false;
	if (num < 0)
	{
		mask->is_negative = true;
		mask->print_sign = true;
		buff = ft_put_unsignednbr_base(ft_abs(num), BASE_DECIMAL, mask);
	}
	else
		buff = ft_put_unsignednbr_base((uintmax_t)num, BASE_DECIMAL, mask);
	return (ft_elem_write(buff, ft_strlen(buff), mask));
}

int	ft_print_unsigned(va_list *arg_list, t_mask *mask)
{
	uintmax_t	num;
	int			base;
	char		*buff;

	num = ft_pull_unsigned(arg_list, &(mask->length_modifiers));\
	mask->print_sign = false;
	mask->free_space = false;
	if (mask->prescision != NOT_SET || mask->left_justified)
		mask->zero_padding = false;
	if (mask->specifier == 'u')
	{
		base = BASE_DECIMAL;
		mask->alternative_mode = false;
	}
	else if (mask->specifier == 'o')
		base = BASE_OCTAL;
	else
		base = BASE_HEX;
	buff = ft_put_unsignednbr_base(num, base, mask);
	return (ft_elem_write(buff, ft_strlen(buff), mask));
}

int	ft_print_percent(va_list *arg_list, t_mask *mask)
{
	(void)arg_list;
	return (ft_elem_write("%", 1, mask));
}
