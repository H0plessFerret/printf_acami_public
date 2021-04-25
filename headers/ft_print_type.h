/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:56:26 by acami             #+#    #+#             */
/*   Updated: 2021/04/25 18:49:56 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_TYPE_H
# define FT_PRINT_TYPE_H

# include <unistd.h>
# include <stddef.h>
# include "ft_printf.h"

int	ft_print_signed(va_list arg_list, t_mask *mask)
{
	intmax_t	num;
	int			base;
	char		*buff;
	char		sign;

	num = ft_pull_signed(arg_list, mask); //hh h l ll z j ...
	if (num < 0)
	{
		buff = ft_put_unsignednbr_base(num * -1, 16, mask);
		sign = '-';
	}
	else
	{
		buff = ft_put_unsignednbr_base(num, 16, mask);
		sign = '+';
	}
	return (ft_magic_write(buff, ft_strlen(buff), mask));
}

int	ft_print_unsigned(va_list arg_list, t_mask *mask)
{
	uintmax_t	num;
	int			base;
	char		*buff;

	num = ft_pull_unsigned(arg_list, mask); //hh h l ll z j ...
	if (mask->mask & SPEC_X_UPPERCASE)
		base = 16;
	buff = ft_put_unsignednbr_base(num, 16, mask);
	return (ft_magic_write(buff, ft_strlen(buff), mask));
}

int	ft_print_char(va_list arg_list, t_mask *mask)
{
	char	c;

	c = va_arg(arg_list, int);
	return (ft_magic_write(&c, 1, mask));
}

int	ft_print_string(va_list arg_list, t_mask *mask)
{
	char	*str;

	str = va_arg(arg_list, char *);
	if (str == NULL)
		str = "(null)";
	return (ft_magic_write(str, ft_strlen(str), mask));
}

int	ft_print_float(va_list arg_list, t_mask *mask);

/*
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
int	ft_print_char_n_times(char sym, int amount_of_times);

// Prints an unsigned integer of the base on the standard output
int	ft_put_unsignednbr_base(unsigned long long nbr, char *base, t_mask *mask);

// Prints an absolute value of a signed integer of the base on standard output
int	ft_put_abs_nbr_base(long long int nbr, char *base, t_mask *mask);
*/
#endif
