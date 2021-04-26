/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_mask_suplimentary.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:18:35 by acami             #+#    #+#             */
/*   Updated: 2021/04/25 19:12:21 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../libft/libft.h"

int	ft_mask_flags(const char *format_spec, t_mask *mask)
{
	char	curr_elem;
	int		count;

	count = 0;
	while (1)
	{
		curr_elem = *(format_spec + count);
		if (curr_elem == '-')
			mask->left_adjusted = true;
		else if (curr_elem == '+')
			mask->print_sign = true;
		else if (curr_elem == ' ')
		{
			if (mask->print_sign)
				mask->free_space = true;
		}
		else if (curr_elem == '#')
			mask->alternative_mode = true;
		else if (curr_elem == '0')
			mask->zero_padding = true;
		else
			break ;
		++count;
	}
	return (count);
}

int	ft_mask_width(const char *format_spec, t_mask *mask, va_list *arg_list)
{
	char	curr_elem;
	int		count;

	count = 0;
	mask->width = NOT_SET;
	curr_elem = *format_spec;
	if (curr_elem == '*')
	{
		mask->width = va_arg(*arg_list, int);
		++count;
	}
	else if (ft_isdigit(curr_elem))
	{
		mask->width = 0;
		while (ft_isdigit(curr_elem))
		{
			mask->width = 10 * mask->width + curr_elem - '0';
			++count;
			curr_elem = *(format_spec + count);
		}
	}
	return (count);
}

int	ft_mask_prescision(const char *format_spec, t_mask *mask, va_list *arg_list)
{
	char	curr_elem;
	int		count;

	mask->prescision = NOT_SET;
	if (*format_spec != '.')
		return (0);
	count = 1;
	mask->prescision = 0;
	curr_elem = *(format_spec + count);
	if (curr_elem == '*')
	{
		mask->prescision = va_arg(*arg_list, int);
		++count;
	}
	else
		while (ft_isdigit(curr_elem))
		{
			mask->prescision = 10 * mask->prescision + curr_elem - '0';
			++count;
			curr_elem = *(format_spec + count);
		}
	return (count);
}

int	ft_mask_length(const char *format_spec, t_mask *mask)
{
	if (*format_spec == 'h' && *(format_spec + 1) == 'h')
	{
		mask->length_modifiers.is_hh = true;
		return (2);
	}
	if (*format_spec == 'l' && *(format_spec + 1) == 'l')
	{
		mask->length_modifiers.is_ll = true;
		return (2);
	}
	if (*format_spec == 'h')
		mask->length_modifiers.is_h = true;
	else if (*format_spec == 'l')
		mask->length_modifiers.is_l = true;
	else if (*format_spec == 'L')
		mask->length_modifiers.is_L = true;
	else if (*format_spec == 'j')
		mask->length_modifiers.is_j = true;
	else if (*format_spec == 'z')
		mask->length_modifiers.is_z = true;
	else
		return (0);
	return (1);
}
