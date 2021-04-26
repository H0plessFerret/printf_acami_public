/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:23:08 by acami             #+#    #+#             */
/*   Updated: 2021/04/25 19:13:20 by acami            ###   ########.fr       */
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

# define	NOT_SET	-1

typedef struct s_length	t_length;
typedef struct s_mask	t_mask;

struct s_length {
	bool	is_hh: 1;
	bool	is_h: 1;
	bool	is_l: 1;
	bool	is_ll: 1;
	bool	is_L: 1;
	bool	is_j: 1;
	bool	is_z: 1;
	bool	is_t: 1;
};

struct s_mask {
	bool		alternative_mode: 1;
	bool		left_adjusted: 1;
	bool		zero_padding: 1;
	bool		free_space:	1;
	bool		print_sign: 1;
	bool		uppercase: 1;
	int			width;
	int			prescision;
	char		specifier;
	t_length	length_modifiers;
};

typedef int	(*t_print_fn)(void *, t_mask *);

int			ft_printf(const char *format_str, ...);
int			ft_dprintf(int fd, const char *format, ...);
int			ft_sprintf(char *str, const char *format, ...);

int			ft_vprintf(const char *format_str, ...);
int			ft_dvprintf(int fd, const char *format, ...);
int			ft_svprintf(char *str, const char *format, ...);

// prints symbols into standart output while % was not encountered
// returns the amount of symbols printed
int			ft_print_till_percent(const char **format_str);

// returns an integer - an amount of symbols read in format_str
// modifies mask with all found flags
int			ft_mask_flags(const char *format_str, t_mask *mask);

// returns an integer - an amount of symbols read in format_str
// modifies mask with all found width parameters
int			ft_mask_width(const char *format_str, t_mask *mask,
va_list *arg_list);

// returns an integer - an amount of symbols read in format_str
// modifies mask with all found prescision parameters
int			ft_mask_prescision(const char *format_str, t_mask *mask,
va_list *arg_list);

// returns an integer - an amount of symbols read in format_str
// modifies mask with all found length parameters
int			ft_mask_length(const char *format_str, t_mask *mask);

// returns 1 if masking process is successful, 0 otherwise
bool		ft_generate_mask(const char **format_str, t_mask *mask,
va_list *arg_list);

// returns a pointer to a function which will print the requested value
t_print_fn	ft_find_corresponding_print(t_mask *mask);

#endif
