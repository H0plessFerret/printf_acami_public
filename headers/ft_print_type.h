/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:56:26 by acami             #+#    #+#             */
/*   Updated: 2021/04/27 15:35:37 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_TYPE_H
# define FT_PRINT_TYPE_H

# include "ft_printf.h"

int	ft_elem_write(char *str, size_t str_len, t_mask *mask);

int	ft_print_signed(va_list *arg_list, t_mask *mask);

int	ft_print_unsigned(va_list *arg_list, t_mask *mask);

int	ft_print_percent(va_list *arg_list, t_mask *mask);

int	ft_print_char(va_list *arg_list, t_mask *mask);

int	ft_print_string(va_list *arg_list, t_mask *mask);

int	ft_print_float(va_list *arg_list, t_mask *mask);

int	ft_print_pointer(va_list *arg_list, t_mask *mask);

int	ft_save_counter(va_list *arg_list, t_mask *mask);

#endif
