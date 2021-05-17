/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:23:08 by acami             #+#    #+#             */
/*   Updated: 2021/05/17 14:02:11 by acami            ###   ########.fr       */
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

# define	NOT_SET			-1
# define	ASCII_MAX		127
# define	DLENGTH_MAX		4940
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

typedef int	(*t_print_fn)(va_list *, t_mask *);

int			ft_printf(const char *format_str, ...);
//int			ft_dprintf(int fd, const char *format, ...);
//int			ft_sprintf(char *str, const char *format, ...);

int			ft_vprintf(const char *format_str, va_list *arg_list);
//int			ft_vdprintf(int fd, const char *format, va_list arg_list);
//int			ft_svprintf(char *str, const char *format, va_list arg_list);

// prints symbols into standart output while % was not encountered
// returns the amount of symbols printed
int			ft_print_till_percent(int fd, const char **format_str);

void		ft_initialize_mask(t_mask *mask);

// returns an integer - an amount of symbols read in format_str
int			ft_mask_flags(const char *format_str, t_mask *mask);

// returns an integer - an amount of symbols read in format_str
int			ft_mask_width(const char *format_str, t_mask *mask,
				va_list *arg_list);

// returns an integer - an amount of symbols read in format_str
int			ft_mask_precision(const char *format_str, t_mask *mask,
				va_list *arg_list);

// returns an integer - an amount of symbols read in format_str
int			ft_mask_length(const char *format_str, t_mask *mask);

// returns 1 if masking process is successful, 0 otherwise
bool		ft_generate_mask(const char **format_str, t_mask *mask,
				va_list *arg_list);

// returns a pointer to a function which will print the requested value
t_print_fn	ft_find_corresponding_print(t_mask *mask);

void		ft_generate_constructor(char *str, size_t str_len, t_mask *mask,
				t_string_constructor *str_const);

#endif
