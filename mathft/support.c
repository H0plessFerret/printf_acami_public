/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:04:23 by acami             #+#    #+#             */
/*   Updated: 2021/05/17 17:26:00 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathft.h"

t_strdouble	*ft_sd_init(void)
{
	t_strdouble	*res;

	res = malloc(sizeof(t_strdouble));
	if (res != NULL)
	{
		res->num_len = 0;
		res->power = 0;
		res->number = NULL;
		res->is_negative = false;
		res->last_sig_digit = 0;
	}
	return (res);
}

bool	ft_resize_number(t_strdouble *number, uint64_t new_len)
{
	char		*buffer;
	uint64_t	copy_size;

	buffer = malloc(new_len + 1);
	if (buffer == NULL)
		return (false);
	free(number->number);
	number->number = buffer;
	buffer[new_len] = '\0';
	if (new_len < number->num_len)
		copy_size = new_len;
	else
		copy_size = number->num_len;
	while (copy_size > 0)
	{
		--copy_size;
		buffer[copy_size] = number->number[copy_size];
	}
	number->num_len = new_len;
	return (true);
}

void	*ft_free_sd(t_strdouble *number)
{
	free(number->number);
	free(number);
	return (NULL);
}

t_strdouble	*ft_copy_sd(t_strdouble *number)
{
	t_strdouble	*res;

	res = malloc(sizeof(t_strdouble));
	if (res != NULL)
	{
		res->is_negative = number->is_negative;
		res->num_len = number->num_len;
		res->number = number->number;
		res->power = number->power;
	}
	return (res);
}
