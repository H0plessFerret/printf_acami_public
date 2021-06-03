/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_strconst_suplimentary.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:18:16 by acami             #+#    #+#             */
/*   Updated: 2021/06/03 12:54:42 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_print_type.h"
#include "../libft/libft.h"

void	ft_initialize_constructor(t_string_constructor *str_const)
{
	str_const->front_spaces = 0;
	ft_bzero(str_const->sign, 3);
	str_const->sign_len = 0;
	str_const->front_zeros = 0;
	str_const->back_zeros = 0;
	str_const->back_spaces = 0;
}

void	ft_generate_sign_info(char *str, t_mask *mask,
t_string_constructor *str_const)
{
	if (mask->print_sign)
		str_const->sign[0] = "+-"[mask->is_negative];
	else if (mask->free_space)
		str_const->sign[0] = ' ';
	else if (mask->alternative_mode && mask->specifier == 'o' && *str != '0')
		str_const->sign[0] = '0';
	else if (mask->alternative_mode && ft_tolower(mask->specifier) == 'x'
		&& *str != '0' && *str != '\0')
	{
		str_const->sign[0] = '0';
		str_const->sign[1] = mask->specifier;
	}
	else if (mask->specifier == 'p' && ft_strncmp(str, "(nil)", 6) != 0)
	{
		str_const->sign[0] = '0';
		str_const->sign[1] = 'x';
	}
	str_const->sign_len = ft_strlen(str_const->sign);
}

void	ft_generate_left_fillers(size_t str_len, t_mask *mask,
t_string_constructor *str_const)
{
	int	symbols_printed;

	if (ft_strchr("diouxX", mask->specifier) != NULL
		&& mask->precision != NOT_SET)
	{
		while (str_len < (uintmax_t)(mask->precision))
		{
			++(str_const->front_zeros);
			++str_len;
		}
		if (!ft_strncmp(str_const->sign, "0", 2) && str_const->front_zeros != 0)
			str_const->sign_len = 0;
	}
	symbols_printed = str_const->sign_len + str_len;
	if (mask->left_justified == false)
	{
		while (symbols_printed < mask->width)
		{
			if (mask->zero_padding)
				++(str_const->front_zeros);
			else
				++(str_const->front_spaces);
			++symbols_printed;
		}
	}
}

void	ft_generate_right_spaces(size_t str_len, t_mask *mask,
t_string_constructor *str_const)
{
	int	symbols_printed;

	if (mask->left_justified)
	{
		symbols_printed = str_const->sign_len + str_const->front_zeros
			+ str_len;
		while (symbols_printed < mask->width)
		{
			++(str_const->back_spaces);
			++symbols_printed;
		}
	}
}
