/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_mask.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:04:49 by acami             #+#    #+#             */
/*   Updated: 2021/04/27 15:27:02 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../libft/libft.h"

static void	ft_initialize_mask(t_mask *mask)
{
	mask->alternative_mode = false;
	mask->left_adjusted	= false;
	mask->zero_padding = false;
	mask->free_space = false;
	mask->print_sign = false;
	mask->uppercase = false;
	mask->is_negative = false;
	mask->width = NOT_SET;
	mask->prescision = NOT_SET;
	mask->specifier = NOT_SET;
	mask->length_modifiers.is_hh = false;
	mask->length_modifiers.is_h = false;
	mask->length_modifiers.is_l = false;
	mask->length_modifiers.is_ll = false;
	mask->length_modifiers.is_L = false;
	mask->length_modifiers.is_j = false;
	mask->length_modifiers.is_z = false;
}

bool	ft_generate_mask(const char **format_spec, t_mask *mask, va_list *arg_list)
{
	int		elems_passed;
	static char	*allowed_values;

	allowed_values = "%diouxXpfFeEgGscn";
	ft_initialize_mask(mask);
	elems_passed = 1;
	elems_passed += ft_mask_flags(*format_spec + elems_passed, mask);
	elems_passed += ft_mask_width(*format_spec + elems_passed, mask, arg_list);
	elems_passed += ft_mask_prescision(*format_spec + elems_passed, mask, arg_list);
	elems_passed += ft_mask_length(*format_spec + elems_passed, mask);
	if (ft_strchr(allowed_values, (int)format_spec[elems_passed]) != NULL)
	{
		mask->width = NOT_SET;
		mask->prescision = NOT_SET;
		return (false);
	}
	mask->specifier = *(format_spec + elems_passed);
	*format_spec += elems_passed + 1;
	return (true);
}
