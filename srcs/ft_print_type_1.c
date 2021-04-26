/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:10:23 by acami             #+#    #+#             */
/*   Updated: 2021/04/25 18:42:44 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_print_type.h"
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
	const char	*base_symbols = "0123456789abcdef";
	size_t		count;
	static char	res[65];

	count = 0;
	if ((nbr == 0) && (mask->prescision != 0))
		write(1, "0", 1);
	while (nbr != 0)
	{
		*(res + count) = base_symbols[nbr % base];
		nbr = (nbr / base);
		++count;
	}
	*(res + count) = '\0';
	ft_strrev(res, count);
	if (mask->uppercase)
		ft_toupper(res);
	return (res);
}

int	ft_print_signed(va_list arg_list, t_mask *mask)
{
	intmax_t	num;
	int			base;
	char		*buff;
	char		sign;

	num = ft_pull_signed(arg_list, mask); //hh h l ll z j ...
	if (num < 0)
	{
		buff = ft_put_unsignednbr_base(num * -1, 16, mask);
	}
	else
	{
		buff = ft_put_unsignednbr_base(num, 16, mask);
	}
	return (ft_magic_write(buff, ft_strlen(buff), mask));
}

int	ft_print_unsigned(va_list arg_list, t_mask *mask)
{
	uintmax_t	num;
	int			base;
	char		*buff;

	num = ft_pull_unsigned(arg_list, mask); //hh h l ll z j ...
	if (mask->mask & SPEC_X_UPPERCASE)
		base = 16;
	buff = ft_put_unsignednbr_base(num, 16, mask);
	return (ft_magic_write(buff, ft_strlen(buff), mask));
}

int	ft_print_percent_sign(va_list arg_list, t_mask *mask)
{
	(void)mask;
	return (write(1, "%", 1));
}

int	ft_print_char(va_list arg_list, t_mask *mask)
{
	char	c;

	c = va_arg(arg_list, int);
	return (ft_magic_write(&c, 1, mask));
}

int	ft_print_string(va_list arg_list, t_mask *mask)
{
	char	*str;

	str = va_arg(arg_list, char *);
	if (str == NULL)
		str = "(null)";
	return (ft_magic_write(str, ft_strlen(str), mask));
}

int	ft_print_float(va_list arg_list, t_mask *mask);
