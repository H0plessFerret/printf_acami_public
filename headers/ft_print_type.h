/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:56:26 by acami             #+#    #+#             */
/*   Updated: 2021/04/23 15:24:06 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_TYPE_H
# define FT_PRINT_TYPE_H

# include <unistd.h>

// Displays char on stanrdard output
int	ft_print_char(void *elem);

// Displays string on stanrdard output
int	ft_print_string(void *elem);

// Displays pointer on stanrdard output
int	ft_print_pointer(void *elem);

// Displays int without the sign on stanrdard output
int	ft_print_abs_int(void *elem);

// Displays unsigned int on stanrdard output
int	ft_print_uint(void *elem);

// Displays unsigned hexadecimal (lowercase) on stanrdard output
int	ft_print_hex(void *elem);

// Displays unsigned hexadecimal (uppercase) on stanrdard output
int	ft_print_hex_upper(void *elem);

// Displays '%' symbol on stanrdard output
int	ft_print_percent_sign(void *elem);

// Displays unsigned octal on stanrdard output
int	ft_print_oct(void *elem);

// Displays floating point number without the sign on stanrdard output
int	ft_print_float(void *elem);

// Displays floating point number in scientific notation
// without the sign on stanrdard output
int	ft_print_scientific(void *elem);

// Displays floating point number in either normal or scientific notation,
// depending which one is the shortest.
int	ft_print_e_f(void *elem);

// Displays hexadecimal floating point number on stanrdard output
int	ft_print_hex_float(void *elem);

// Saves the amount of elements were printed by the current call of FT_PRINTF
// to the elem
int	ft_save_printed(void *elem);

// Prints sym on standard output amount_of_times times
int	ft_print_char_n(char sym, int amount_of_times);

// Prints an unsigned integer of the base on the standard output
int	ft_put_unsignednbr_base(size_t nbr, char *base);

// Prints an absolute value of a signed integer of the base on standard output
int	ft_put_abs_nbr_base(int nbr, char *base);

#endif
