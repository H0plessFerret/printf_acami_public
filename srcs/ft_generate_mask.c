/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_mask.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:04:49 by acami             #+#    #+#             */
/*   Updated: 2021/05/17 14:02:10 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../libft/libft.h"

void	ft_initialize_mask(t_mask *mask)
{
	mask->alternative_mode = false;
	mask->left_justified = false;
	mask->zero_padding = false;
	mask->free_space = false;
	mask->print_sign = false;
	mask->uppercase = false;
	mask->is_negative = false;
	mask->width = NOT_SET;
	mask->precision = NOT_SET;
	mask->specifier = NOT_SET;
	mask->length_modifiers.is_hh = false;
	mask->length_modifiers.is_h = false;
	mask->length_modifiers.is_l = false;
	mask->length_modifiers.is_ll = false;
	mask->length_modifiers.is_L = false;
	mask->length_modifiers.is_j = false;
	mask->length_modifiers.is_z = false;
}

bool	ft_generate_mask(const char **format_spec, t_mask *mask,
va_list *arg_list)
{
	int			elems_passed;
	static char	*allowed_values;

	allowed_values = "%diouxXpfFeEgGscn";
	ft_initialize_mask(mask);
	elems_passed = 1;
	elems_passed += ft_mask_flags(*format_spec + elems_passed, mask);
	elems_passed += ft_mask_width(*format_spec + elems_passed, mask, arg_list);
	elems_passed += ft_mask_precision(*format_spec + elems_passed,
			mask, arg_list);
	elems_passed += ft_mask_length(*format_spec + elems_passed, mask);
	if (*(*format_spec + elems_passed) == '\0'
		|| ft_strchr(allowed_values, *(*format_spec + elems_passed)) == NULL)
	{
		mask->width = NOT_SET;
		mask->precision = NOT_SET;
		return (false);
	}
	if (ft_strchr("XFEG", *(*format_spec + elems_passed)) != NULL)
		mask->uppercase = true;
	mask->specifier = *(*format_spec + elems_passed);
	*format_spec += elems_passed + 1;
	return (true);
}
