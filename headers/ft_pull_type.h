/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pull_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:45:30 by acami             #+#    #+#             */
/*   Updated: 2021/04/27 15:11:38 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PULL_TYPE_H
# define FT_PULL_TYPE_H

#include "ft_printf.h"

intmax_t	ft_pull_signed(va_list *arg_list, t_length *length_modifiers);

uintmax_t	ft_pull_unsigned(va_list *arg_list, t_length *length_modifiers);

wint_t		ft_pull_char(va_list *arg_list, t_length *length_modifiers);

wchar_t		*ft_pull_string(va_list *arg_list, t_length *length_modifiers);

long double	ft_pull_float(va_list *arg_list, t_length *length_modifiers);

void		*ft_pull_pointer(va_list *arg_list, t_length *length_modifiers);

intmax_t	*ft_pull_counter(va_list *arg_list, t_length *length_modifiers);

#endif