/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:52:46 by acami             #+#    #+#             */
/*   Updated: 2021/04/19 15:37:44 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int character, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		if (*(unsigned char *)(str + count) == (unsigned char)character)
			return ((void *)str + count);
		++count;
	}
	return (NULL);
}
