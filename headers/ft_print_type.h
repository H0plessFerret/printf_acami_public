/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:56:26 by acami             #+#    #+#             */
/*   Updated: 2021/04/22 20:02:39 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_TYPE_H
# define FT_PRINT_TYPE_H

// Displays int on standart output
int	ft_print_int(void *elem);

// Displays unsigned int on standart output
int	ft_print_uint(void *elem);

// Displays unsigned octal on standart output
int	ft_print_oct(void *elem);

// Displays unsigned hexadecimal (lowercase) on standart output
int	ft_print_hex(void *elem);

// Displays unsigned hexadecimal (uppercase) on standart output
int	ft_print_hex_upper(void *elem);

// Displays floating point number on standart output
int	ft_print_float(void *elem);

// Displays floating point number in scientific notation on standart output
int	ft_print_scientific(void *elem);

// Displays floating point number in either normal or scientific notation,
// depending which one is the shortest.
int	ft_print_e_f(void *elem);

// Displays hexadecimal floating point number on standart output
int	ft_print_hex_float(void *elem);

// Displays char on standart output
int	ft_print_char(void *elem);

// Displays string on standart output
int	ft_print_string(void *elem);

// Displays pointer on standart output
int	ft_print_pointer(void *elem);

// Saves the amount of elements were printed by the current call of FT_PRINTF
// to the elem
int	ft_save_printed(void *elem);

// Prints sym on standard output amount_of_times times
int	ft_print_char_n(char sym, int amount_of_times);

#endif
