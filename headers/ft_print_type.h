/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:56:26 by acami             #+#    #+#             */
/*   Updated: 2021/05/19 16:34:53 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_TYPE_H
# define FT_PRINT_TYPE_H

# include "ft_printf.h"

int			ft_elem_write(char *str, size_t str_len, t_mask *mask);

int			ft_print_signed(va_list *arg_list, t_mask *mask);

int			ft_print_unsigned(va_list *arg_list, t_mask *mask);

int			ft_print_percent(va_list *arg_list, t_mask *mask);

int			ft_print_char(va_list *arg_list, t_mask *mask);

int			ft_print_string(va_list *arg_list, t_mask *mask);

int			ft_print_float(va_list *arg_list, t_mask *mask);

int			ft_print_pointer(va_list *arg_list, t_mask *mask);

int			ft_save_counter(va_list *arg_list, t_mask *mask);

char		*ft_put_unsignednbr_base(uintmax_t nbr, int8_t base, t_mask *mask);

void		ft_initialize_constructor(t_string_constructor *str_const);

void		ft_generate_sign_info(char *str, t_mask *mask,
				t_string_constructor *str_const);

void		ft_generate_right_zeroes(t_mask *mask,
				t_string_constructor *str_const);

void		ft_generate_left_fillers(size_t str_len, t_mask *mask,
				t_string_constructor *str_const);

void		ft_generate_right_spaces(size_t str_len, t_mask *mask,
				t_string_constructor *str_const);

///////////////// AMMA FIRIN MAH LAZOR
char		*ft_put_unsignedfloat_base(long double nbr, int8_t base,
				t_mask *mask);

long double	ft_pow_base(int8_t base, int8_t power);

void		ft_correct_bad_precision(long double *nbr, int8_t *nbr_power,
				int8_t base);

void		ft_norm_float_base(long double *nbr, int8_t *nbr_power,
				int8_t base);

int8_t		ft_find_power(long double nbr, int8_t base);

char		*ft_put_fraction_base(long double nbr, int8_t base, t_mask *mask);

char		*ft_put_float_normal_base(long double nbr, int8_t base,
				t_mask *mask, int8_t nbr_power);

char		*ft_put_float_scientific_base(long double nbr, int8_t base,
				t_mask *mask, int8_t nbr_power);

char		*ft_put_float_g_base(long double nbr, int8_t base,
				t_mask *mask, int8_t nbr_power);

uintmax_t	ft_abs(intmax_t num);

#endif
