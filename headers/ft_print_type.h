/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:56:26 by acami             #+#    #+#             */
/*   Updated: 2021/06/03 13:23:27 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_TYPE_H
# define FT_PRINT_TYPE_H

# include "ft_printf.h"

int			ft_elem_write(t_cbuffer *cbuffer, char *str, size_t str_len,
				t_mask *mask);

int			ft_print_signed(t_cbuffer *cbuffer, va_list *arg_list,
				t_mask *mask);

int			ft_print_unsigned(t_cbuffer *cbuffer, va_list *arg_list,
				t_mask *mask);

int			ft_print_percent(t_cbuffer *cbuffer, va_list *arg_list,
				t_mask *mask);

int			ft_print_char(t_cbuffer *cbuffer, va_list *arg_list, t_mask *mask);

int			ft_print_string(t_cbuffer *cbuffer, va_list *arg_list,
				t_mask *mask);

int			ft_print_pointer(t_cbuffer *cbuffer, va_list *arg_list,
				t_mask *mask);

int			ft_save_counter(t_cbuffer *cbuffer, va_list *arg_list,
				t_mask *mask);

char		*ft_put_unsignednbr_base(uintmax_t nbr, int8_t base, t_mask *mask);

uintmax_t	ft_abs(intmax_t num);

size_t		ft_wint_convertion(char *res, wint_t character,
				int32_t len_allowed);

size_t		ft_wstr_convertion(char **res, wchar_t *str, int32_t max_len);

#endif
