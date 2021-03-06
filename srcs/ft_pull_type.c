/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pull_type_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:58:19 by acami             #+#    #+#             */
/*   Updated: 2021/05/19 14:43:23 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_pull_type.h"

intmax_t	ft_pull_signed(va_list *arg_list, t_length *length_modifiers)
{
	if (length_modifiers->is_hh)
		return ((intmax_t)((char)va_arg(*arg_list, int)));
	else if (length_modifiers->is_h)
		return ((intmax_t)((short int)va_arg(*arg_list, int)));
	else if (length_modifiers->is_l)
		return ((intmax_t)va_arg(*arg_list, long int));
	else if (length_modifiers->is_ll)
		return ((intmax_t)va_arg(*arg_list, long long int));
	else if (length_modifiers->is_j)
		return (va_arg(*arg_list, intmax_t));
	else if (length_modifiers->is_z)
		return ((intmax_t)va_arg(*arg_list, ssize_t));
	else
		return ((intmax_t)va_arg(*arg_list, int));
}

uintmax_t	ft_pull_unsigned(va_list *arg_list, t_length *length_modifiers)
{
	if (length_modifiers->is_hh)
		return ((uintmax_t)((unsigned char)va_arg(*arg_list, int)));
	else if (length_modifiers->is_h)
		return ((uintmax_t)((unsigned short int)va_arg(*arg_list, int)));
	else if (length_modifiers->is_l)
		return ((uintmax_t)va_arg(*arg_list, unsigned long int));
	else if (length_modifiers->is_ll)
		return ((uintmax_t)va_arg(*arg_list, unsigned long long int));
	else if (length_modifiers->is_j)
		return (va_arg(*arg_list, uintmax_t));
	else if (length_modifiers->is_z)
		return ((uintmax_t)va_arg(*arg_list, size_t));
	return ((uintmax_t)va_arg(*arg_list, unsigned int));
}

wint_t	ft_pull_char(va_list *arg_list, t_length *length_modifiers)
{
	if (length_modifiers->is_l)
		return (va_arg(*arg_list, wint_t));
	return ((wint_t)va_arg(*arg_list, int));
}

long double	ft_pull_float(va_list *arg_list, t_length *length_modifiers)
{
	if (length_modifiers->is_L)
		return (va_arg(*arg_list, long double));
	return ((long double)va_arg(*arg_list, double));
}

void	*ft_pull_pointer(va_list *arg_list, t_length *length_modifiers)
{
	(void)length_modifiers;
	return (va_arg(*arg_list, void *));
}
