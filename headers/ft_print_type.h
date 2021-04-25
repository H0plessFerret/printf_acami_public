/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:56:26 by acami             #+#    #+#             */
/*   Updated: 2021/04/25 18:09:59 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_TYPE_H
# define FT_PRINT_TYPE_H

# include <unistd.h>
# include <stddef.h>
# include "ft_printf.h"

// Displays char on stanrdard output
int	ft_print_char(void *elem, t_mask *mask);

// Displays string on stanrdard output
int	ft_print_string(void *elem, t_mask *mask);

// Displays pointer on stanrdard output
int	ft_print_pointer(void *elem, t_mask *mask);

// Displays int without the sign on stanrdard output
int	ft_print_abs_int(void *elem, t_mask *mask);

// Displays unsigned int on stanrdard output
int	ft_print_uint(void *elem, t_mask *mask);

// Displays unsigned hexadecimal (lowercase) on stanrdard output
int	ft_print_hex(void *elem, t_mask *mask);

// Displays unsigned hexadecimal (uppercase) on stanrdard output
int	ft_print_hex_upper(void *elem, t_mask *mask);

// Displays '%' symbol on stanrdard output
int	ft_print_percent_sign(void *elem, t_mask *mask);

// Displays unsigned octal on stanrdard output
int	ft_print_oct(void *elem, t_mask *mask);

// Displays floating point number without the sign on stanrdard output
int	ft_print_abs_float(void *elem, t_mask *mask);

// Displays floating point number in scientific notation
// without the sign on stanrdard output
int	ft_print_scientific(void *elem, t_mask *mask);

// Displays floating point number in either normal or scientific notation,
// depending which one is the shortest.
int	ft_print_e_f(void *elem, t_mask *mask);

// Displays hexadecimal floating point number on stanrdard output
int	ft_print_hex_float(void *elem, t_mask *mask);

// Saves the amount of elements were printed by the current call of FT_PRINTF
// to the elem
int	ft_save_printed(void *elem, int saved);

// Prints sym on standard output amount_of_times times
int	ft_print_char_n(char sym, int amount_of_times);

// Prints an unsigned integer of the base on the standard output
int	ft_put_unsignednbr_base(unsigned long long nbr, char *base, t_mask *mask);

// Prints an absolute value of a signed integer of the base on standard output
int	ft_put_abs_nbr_base(long long int nbr, char *base, t_mask *mask);

#endif
