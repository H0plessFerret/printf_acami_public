/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:34:51 by acami             #+#    #+#             */
/*   Updated: 2021/04/19 15:37:43 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int character, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		*(unsigned char *)(dest + count) = *(unsigned char *)(src + count);
		if (*(unsigned char *)(src + count) == (unsigned char)character)
			return (dest + count + 1);
		++count;
	}
	return (NULL);
}
