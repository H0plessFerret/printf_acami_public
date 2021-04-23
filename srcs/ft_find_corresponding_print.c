/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_corresponding_print.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:46:55 by acami             #+#    #+#             */
/*   Updated: 2021/04/23 21:07:35 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../headers/ft_print_type.h"

static int	(*ft_find_corresponding_print_bonus(uint32_t mask))(void *data,
int prescision)
{
	if ((mask & SPEC_O) != 0)
		return (ft_print_oct);
	else if ((mask & SPEC_F) != 0)
		return (ft_print_abs_float);
	else if ((mask & SPEC_E) != 0)
		return (ft_print_scientific);
	else if ((mask & SPEC_G) != 0)
		return (ft_print_e_f);
	else if ((mask & SPEC_N) != 0)
		return (ft_save_printed);
	else if ((mask & SPEC_A) != 0)
		return (ft_print_hex_float);
	else
		return (NULL);
}

int	(*ft_find_corresponding_print(uint32_t mask))(void *data,
int prescision)
{
	if ((mask & SPEC_C) != 0)
		return (ft_print_char);
	else if ((mask & SPEC_S) != 0)
		return (ft_print_string);
	else if ((mask & SPEC_P) != 0)
		return (ft_print_pointer);
	else if ((mask & SPEC_D_I) != 0)
		return (ft_print_abs_int);
	else if ((mask & SPEC_U) != 0)
		return (ft_print_uint);
	else if ((mask & SPEC_X) != 0)
		return (ft_print_hex);
	else if ((mask & SPEC_X_UPPERCASE) != 0)
		return (ft_print_hex_upper);
	else if ((mask & SPEC_PERCENT) != 0)
		return (ft_print_percent_sign);
	else
		return (ft_find_corresponding_print_bonus(mask));
}
