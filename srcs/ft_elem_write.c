/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:32:51 by acami             #+#    #+#             */
/*   Updated: 2021/05/21 22:01:31 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_print_type.h"
#include "../libft/libft.h"

int	ft_elem_write(t_cbuffer *cbuffer, char *str, size_t str_len, t_mask *mask)
{
	int						res;
	t_string_constructor	str_const;

	ft_generate_constructor(str, str_len, mask, &str_const);
	res = 0;
	while ((str_const.front_spaces)-- > 0)
		res += ft_insert_cbuffer(cbuffer, " ", 1);
	res += ft_insert_cbuffer(cbuffer, str_const.sign, str_const.sign_len);
	while ((str_const.front_zeros)-- > 0)
		res += ft_insert_cbuffer(cbuffer, "0", 1);
	res += ft_insert_cbuffer(cbuffer, str, str_len);
	while ((str_const.back_zeros)-- > 0)
		res += ft_insert_cbuffer(cbuffer, "0", 1);
	while ((str_const.back_spaces)-- > 0)
		res += ft_insert_cbuffer(cbuffer, " ", 1);
	return (res);
}
