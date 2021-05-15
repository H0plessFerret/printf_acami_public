/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:27:25 by acami             #+#    #+#             */
/*   Updated: 2021/04/29 00:27:25 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_print_type.h"
#include "../headers/ft_pull_type.h"
#include "../libft/libft.h"

int	ft_print_char(va_list *arg_list, t_mask *mask)
{
	char	buffer;

	mask->alternative_mode = false;
	mask->free_space = false;
	mask->print_sign = false;
	mask->zero_padding = false;
	buffer = ft_pull_char(arg_list, &(mask->length_modifiers));
	return (ft_elem_write(&buffer, 1, mask));
}

int	ft_print_string(va_list *arg_list, t_mask *mask)
{
	char	*str;

	str = ft_pull_pointer(arg_list, &(mask->length_modifiers));
	mask->alternative_mode = false;
	mask->free_space = false;
	mask->print_sign = false;
	mask->zero_padding = false;
	if (str == NULL)
	{
		if (mask->prescision > 5 || mask->prescision == NOT_SET)
			str = "(null)";
		else
			str = "";
	}
	else if (mask->prescision != NOT_SET 
			&& (uintmax_t)(mask->prescision) < ft_strlen(str))
		return (ft_elem_write(str, mask->prescision, mask));
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
	if (ptr == NULL)
		str = "(nil)";
	else
		str = ft_put_unsignednbr_base((uintmax_t)ptr, BASE_HEX, mask);
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
	long double	num;
	int			base;
	char		*buff;

	base = BASE_DECIMAL;
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
