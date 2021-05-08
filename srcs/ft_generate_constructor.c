/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_constructor.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:18:16 by acami             #+#    #+#             */
/*   Updated: 2021/05/08 15:18:16 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_print_type.h"
#include "../libft/libft.h"

static void	ft_initialize_constructor(t_string_constructor *str_const)
{
	str_const->front_spaces = 0;
	ft_bzero(str_const->sign, 3);
	str_const->sign_len = 0;
	str_const->front_zeros = 0;
	str_const->back_zeros = 0;
	str_const->back_spaces = 0;
}

static void	ft_generate_sign_info(char *str, t_mask *mask,
t_string_constructor *str_const)
{
	if (mask->print_sign)
		str_const->sign[0] = "+-"[mask->is_negative];
	else if (mask->free_space)
		str_const->sign[0] = ' ';
	else if (mask->alternative_mode && mask->specifier == 'o' && *str != '0')
		str_const->sign[0] = '0';
	else if (mask->alternative_mode && ft_tolower(mask->specifier) == 'x')
	{
		str_const->sign[0] = '0';
		str_const->sign[1] = mask->specifier;
	}
	else if (mask->specifier == 'p' && ft_strncmp(str, "(null)", 7) == 0)
	{
		str_const->sign[0] = '0';
		str_const->sign[1] = 'x';
	}
	str_const->sign_len = ft_strlen(str_const->sign);
}

static void ft_generate_right_fillers(size_t str_len, t_mask *mask,
t_string_constructor *str_const)
{
	int	prescision;
	int	symbols_printed;

	prescision = mask->prescision;
	if (ft_strchr("fFeE", mask->specifier) != NULL)
		while (DLENGTH_MAX < prescision)
		{
			++(str_const->back_zeros);
			++prescision;
		}
	symbols_printed = mask->zero_padding + str_len + mask->print_sign;
	if (mask->left_justified)
		while (symbols_printed < mask->width)
		{
			++(str_const->back_spaces);
			++symbols_printed;
		}
}

static void ft_generate_left_fillers(size_t str_len, t_mask *mask,
t_string_constructor *str_const)
{
	int	symbols_printed;

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

void	ft_generate_constructor(char *str, size_t str_len, t_mask *mask,
t_string_constructor *str_const)
{
	ft_initialize_constructor(str_const);
	ft_generate_sign_info(str, mask, str_const);
	ft_generate_right_fillers(str_len, mask, str_const);
	ft_generate_left_fillers(str_len, mask, str_const);
}
