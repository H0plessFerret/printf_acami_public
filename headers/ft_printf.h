/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:23:08 by acami             #+#    #+#             */
/*   Updated: 2021/05/25 22:10:00 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>
# include <wchar.h>
# include <limits.h>
# include "ft_cbuff.h"

# define	NOT_SET			-1
# define	ASCII_MAX		127
# define	DLENGTH_MAX		4940
# define	CBUFFER_LEN		256
# define	BASE_OCTAL		8
# define	BASE_DECIMAL	10
# define	BASE_HEX		16

typedef struct s_length				t_length;
typedef struct s_mask				t_mask;
typedef struct s_string_constructor	t_string_constructor;

struct s_length
{
	bool	is_hh : 1;
	bool	is_h : 1;
	bool	is_l : 1;
	bool	is_ll : 1;
	bool	is_L : 1;
	bool	is_j : 1;
	bool	is_z : 1;
};

struct s_mask
{
	bool		alternative_mode : 1;
	bool		left_justified : 1;
	bool		zero_padding : 1;
	bool		free_space : 1;
	bool		print_sign : 1;
	bool		uppercase : 1;
	bool		is_negative : 1;
	int32_t		width;
	int32_t		precision;
	int32_t		symbols_printed;
	char		specifier;
	t_length	length_modifiers;
};

struct s_string_constructor
{
	intmax_t	front_spaces;
	char		sign[3];
	int8_t		sign_len;
	intmax_t	front_zeros;
	intmax_t	back_zeros;
	intmax_t	back_spaces;
};

typedef int	(*t_print_fn)(t_cbuffer *, va_list *, t_mask *);

int			ft_printf(const char *format_str, ...);

int			ft_vprintf(const char *format_str, va_list *arg_list);

// Print symbols onto standart output while % was not encountered
// returns the amount of symbols printed
int			ft_print_till_percent(t_cbuffer *cbuffer,
				const char **format_spec);

// Initializes the mask with default field values
void		ft_initialize_mask(t_mask *mask);

// Modifies the mask with information about flags given by user
// Returns an integer - an amount of symbols read in format_str
int			ft_mask_flags(const char *format_str, t_mask *mask);

// Modifies the mask with information about width given by user
// returns an integer - an amount of symbols read in format_str
int			ft_mask_width(const char *format_str, t_mask *mask,
				va_list *arg_list);

// Modifies the mask with information about precision given by user
// returns an integer - an amount of symbols read in format_str
int			ft_mask_precision(const char *format_str, t_mask *mask,
				va_list *arg_list);

// Modifies the mask with information about length given by user
// returns an integer - an amount of symbols read in format_str
int			ft_mask_length(const char *format_str, t_mask *mask);

// Generates mask given a specifeir string
// returns 1 if masking process is successful, 0 otherwise
bool		ft_generate_mask(const char **format_str, t_mask *mask,
				va_list *arg_list);

// Finds a pointer to a function which will print the requested type
// and returns it
t_print_fn	ft_find_corresponding_print(t_mask *mask);

// Initializes the string constructor with default field values
void		ft_initialize_constructor(t_string_constructor *str_const);

void		ft_generate_sign_info(char *str, t_mask *mask,
				t_string_constructor *str_const);

void		ft_generate_right_zeroes(t_mask *mask,
				t_string_constructor *str_const);

void		ft_generate_left_fillers(size_t str_len, t_mask *mask,
				t_string_constructor *str_const);

void		ft_generate_right_spaces(size_t str_len, t_mask *mask,
				t_string_constructor *str_const);

void		ft_generate_constructor(char *str, size_t str_len, t_mask *mask,
				t_string_constructor *str_const);

size_t		ft_wint_convertion(char *res, wint_t character,
				int32_t len_allowed);
size_t		ft_wstr_convertion(char **res, wchar_t *str, int32_t max_len);

#endif
