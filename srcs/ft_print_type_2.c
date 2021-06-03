/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:27:25 by acami             #+#    #+#             */
/*   Updated: 2021/05/25 22:51:34 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_print_type.h"
#include "../headers/ft_pull_type.h"
#include "../headers/ft_printf.h"
#include "../libft/libft.h"

int	ft_print_char(t_cbuffer *cbuffer, va_list *arg_list, t_mask *mask)
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
	return (ft_elem_write(cbuffer, buffer, len, mask));
}

int	ft_print_string(t_cbuffer *cbuffer, va_list *arg_list, t_mask *mask)
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
		elems_printed = ft_elem_write(cbuffer, buffer, tmp, mask);
		free(buffer);
		return (elems_printed);
	}
	if (mask->precision != NOT_SET
		&& (uintmax_t)(mask->precision) < ft_strlen(str))
		return (ft_elem_write(cbuffer, str, mask->precision, mask));
	return (ft_elem_write(cbuffer, str, ft_strlen(str), mask));
}

int	ft_print_pointer(t_cbuffer *cbuffer, va_list *arg_list, t_mask *mask)
{
	void	*ptr;
	char	*str;

	ptr = ft_pull_pointer(arg_list, &(mask->length_modifiers));
	mask->alternative_mode = true;
	mask->free_space = false;
	mask->print_sign = false;
	mask->zero_padding = false;
	str = ft_put_unsignednbr_base((uintmax_t)ptr, BASE_HEX, mask);
	return (ft_elem_write(cbuffer, str, ft_strlen(str), mask));
}

int	ft_save_counter(t_cbuffer *cbuffer, va_list *arg_list, t_mask *mask)
{
	void	*to_write;
	int		elems_printed;

	elems_printed = ft_print_cbuffer(cbuffer);
	mask->symbols_printed += elems_printed;
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
	return (elems_printed);
}

uintmax_t	ft_abs(intmax_t num)
{
	if (num == INTMAX_MIN)
		return ((uintmax_t)INTMAX_MAX + 1);
	if (num < 0)
		return (num * -1);
	return (num);
}
