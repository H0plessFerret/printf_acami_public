/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:10:23 by acami             #+#    #+#             */
/*   Updated: 2021/04/27 15:27:48 by acami            ###   ########.fr       */
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

char	*ft_put_unsignednbr_base(uintmax_t nbr, int base, t_mask *mask)
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
		ft_toupper(res);
	return (res);
}

int	ft_print_signed(va_list *arg_list, t_mask *mask)
{
	intmax_t	num;
	char		*buff;
	char		sign;

	num = ft_pull_signed(arg_list, &(mask->length_modifiers));
	if (num < 0)
	{
		mask->is_negative = true;
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
		str = "(null)";
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
	*to_write = mask->symbols_printed;
	return (0);
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