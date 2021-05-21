/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:27:25 by acami             #+#    #+#             */
/*   Updated: 2021/05/21 16:11:38 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_print_type.h"
#include "../headers/ft_pull_type.h"
#include "../headers/ft_printf.h"
#include "../libft/libft.h"

int	ft_print_char(va_list *arg_list, t_mask *mask)
{
	wint_t	character;
	char	buffer[4];
	size_t	len;

	mask->alternative_mode = false;
	mask->free_space = false;
	mask->print_sign = false;
	mask->zero_padding = false;
	character = ft_pull_char(arg_list, &(mask->length_modifiers));
	if (mask->length_modifiers.is_l)
		len = ft_wint_convertion(buffer, character, mask->precision);
	else
	{
		buffer[0] = (char)character;
		len = 1;
	}
	return (ft_elem_write(buffer, len, mask));
}

int	ft_print_string(va_list *arg_list, t_mask *mask)
{
	char	*str;
	char	*buffer;
	int		elems_printed;
	size_t	tmp;

	str = ft_pull_pointer(arg_list, &(mask->length_modifiers));
	mask->alternative_mode = false;
	mask->free_space = false;
	mask->print_sign = false;
	mask->zero_padding = false;
	if (str == NULL)
		str = "(null)";
	else if (mask->length_modifiers.is_l)
	{
		buffer = NULL;
		tmp = ft_wstr_convertion(&buffer, (wchar_t *)str, mask->precision);
		elems_printed = ft_elem_write(buffer, tmp, mask);
		free(buffer);
		return (elems_printed);
	}
	if (mask->precision != NOT_SET
		&& (uintmax_t)(mask->precision) < ft_strlen(str))
		return (ft_elem_write(str, mask->precision, mask));
	return (ft_elem_write(str, ft_strlen(str), mask));
}

int	ft_print_pointer(va_list *arg_list, t_mask *mask)
{
	void	*ptr;
	char	*str;

	ptr = ft_pull_pointer(arg_list, &(mask->length_modifiers));
	mask->alternative_mode = true;
	mask->free_space = false;
	mask->print_sign = false;
	mask->zero_padding = false;
	str = ft_put_unsignednbr_base((uintmax_t)ptr, BASE_HEX, mask);
	return (ft_elem_write(str, ft_strlen(str), mask));
}

int	ft_save_counter(va_list *arg_list, t_mask *mask)
{
	void	*to_write;

	to_write = ft_pull_pointer(arg_list, &(mask->length_modifiers));
	if (mask->length_modifiers.is_hh)
		*(signed char *)to_write = (signed char)(mask->symbols_printed);
	else if (mask->length_modifiers.is_h)
		*(short int *)to_write = (short int)(mask->symbols_printed);
	else if (mask->length_modifiers.is_l)
		*(long int *)to_write = (long int)(mask->symbols_printed);
	else if (mask->length_modifiers.is_ll)
		*(long long int *)to_write = (long long int)(mask->symbols_printed);
	else if (mask->length_modifiers.is_j)
		*(intmax_t *)to_write = (intmax_t)(mask->symbols_printed);
	else if (mask->length_modifiers.is_z)
		*(size_t *)to_write = (size_t)(mask->symbols_printed);
	else
		*(int *)to_write = (int)(mask->symbols_printed);
	return (0);
}

int	ft_print_float(va_list *arg_list, t_mask *mask)
{
	long double	num;
	int			base;
	char		*buff;

	base = BASE_DECIMAL;
	if (mask->precision == NOT_SET)
		mask->precision = 6;
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
