/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_corresponding_print.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:46:55 by acami             #+#    #+#             */
/*   Updated: 2021/04/25 18:10:28 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../headers/ft_print_type.h"

t_print_fn	printft_find_corresponding_print(t_mask *mask)
{
	static const t_print_fn print_fns[ASCII_MAX] = {
		['%'] = ft_print_percent,
		['d'] = ft_print_signed,
		['i'] = ft_print_signed,
		['o'] = ft_print_unsigned,
		['u'] = ft_print_unsigned,
		['x'] = ft_print_unsigned,
		['X'] = ft_print_unsigned,
		['p'] = ft_print_pointer,
		['f'] = ft_print_float,
		['F'] = ft_print_float,
		['e'] = ft_print_float,
		['E'] = ft_print_float,
		['g'] = ft_print_float,
		['G'] = ft_print_float,
		['s'] = ft_print_string,
		['c'] = ft_print_char,
		['n'] = ft_save_counter
	};
	
	return (print_fns[mask->specifier & ASCII_MAX]);
}
