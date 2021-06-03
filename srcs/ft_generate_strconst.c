/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_strconst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:31:15 by acami             #+#    #+#             */
/*   Updated: 2021/06/03 12:54:49 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_print_type.h"
#include "../libft/libft.h"

void	ft_generate_constructor(char *str, size_t str_len, t_mask *mask,
t_string_constructor *str_const)
{
	ft_initialize_constructor(str_const);
	ft_generate_sign_info(str, mask, str_const);
	ft_generate_left_fillers(str_len, mask, str_const);
	ft_generate_right_spaces(str_len, mask, str_const);
}
