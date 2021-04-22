/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:56:26 by acami             #+#    #+#             */
/*   Updated: 2021/04/21 19:08:38 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_TYPE_H
# define FT_PRINT_TYPE_H

// Displays int on standart output
// flag extra is added to support some width flags
int	ft_print_int(void *elem, int extra);

// Displays unsigned int on standart output
// flag extra is added to support some width flags
int	ft_print_uint(void *elem, int extra);

// Displays unsigned octal on standart output
// flag extra is added to support some width flags
int	ft_print_oct(void *elem, int extra);

// Displays unsigned hexadecimal (lowercase) on standart output
// flag extra is added to support some width flags
int	ft_print_hex(void *elem, int extra);

// Displays unsigned hexadecimal (uppercase) on standart output
// flag extra is added to support some width flags
int	ft_print_hex_upper(void *elem, int extra);

// Displays floating point number on standart output
// flag extra is added to support some width flags
int	ft_print_float(void *elem, int extra);

// Displays floating point number in scientific notation on standart output
// flag extra is added to support some width flags
int	ft_print_scientific(void *elem, int extra);

// Displays floating point number in either normal or scientific notation,
// depending which one is the shortest.
// flag extra is added to support some width flags
int	ft_print_e_f(void *elem, int extra);

// Displays hexadecimal floating point number on standart output
// flag extra is added to support some width flags
int	ft_print_hex_float(void *elem, int extra);

// Displays char on standart output
// flag extra is added to support some width flags
int	ft_print_char(void *elem, int extra);

// Displays string on standart output
// flag extra is added to support some width flags
int	ft_print_string(void *elem, int extra);

// Displays pointer on standart output
// flag extra is added to support some width flags
int	ft_print_pointer(void *elem, int extra);

// Saves the amount of elements were printed by the current call of FT_PRINTF
// to the elem
// flag extra is added to support some width flags
int	ft_save_printed(void *elem, int extra);

// Prints sym on standard output amount_of_times times
int	ft_print_char_n(char sym, int amount_of_times);

#endif
