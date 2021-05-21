/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cbuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:10:59 by acami             #+#    #+#             */
/*   Updated: 2021/05/21 23:02:03 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_cbuff.h"

t_cbuffer	*ft_init_cbuffer(size_t size, int associated_fd)
{
	t_cbuffer	*res;

	res = malloc(sizeof(t_cbuffer));
	if (res == NULL)
		return (NULL);
	res->data = malloc(size);
	if (res->data == NULL)
	{
		free(res);
		return (NULL);
	}
	res->error_occured = false;
	res->curr_pos = 0;
	res->size = size;
	res->associated_fd = associated_fd;
	return (res);
}

int	ft_close_cbuffer(t_cbuffer *cbuffer)
{
	int	elems_printed;

	elems_printed = ft_print_cbuffer(cbuffer);
	free(cbuffer->data);
	free(cbuffer);
	return (elems_printed);
}

int	ft_insert_cbuffer(t_cbuffer *cbuffer, const char *str, size_t str_len)
{
	size_t	count;
	size_t	elems_printed;

	count = 0;
	elems_printed = 0;
	while (count < str_len)
	{
		cbuffer->data[cbuffer->curr_pos] = str[count];
		++(cbuffer->curr_pos);
		if (str[count] == '\n' || cbuffer->curr_pos == cbuffer->size
			|| count == str_len)
			elems_printed += ft_print_cbuffer(cbuffer);
		++count;
	}
	return (elems_printed);
}

int	ft_print_cbuffer(t_cbuffer *cbuffer)
{
	int	write_res;

	write_res = write(cbuffer->associated_fd, cbuffer->data, cbuffer->curr_pos);
	cbuffer->curr_pos = 0;
	if (write_res == -1)
		cbuffer->error_occured = true;
	return (write_res);
}
