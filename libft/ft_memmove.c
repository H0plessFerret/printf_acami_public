/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:39:38 by acami             #+#    #+#             */
/*   Updated: 2021/04/19 15:38:12 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	count;

	if (dest < src)
	{
		count = 0;
		while (count < len)
		{
			*(unsigned char *)(dest + count) = *(unsigned char *)(src + count);
			++count;
		}
	}
	else if (dest > src)
	{
		count = len;
		while (count != 0)
		{
			--count;
			*(unsigned char *)(dest + count)
				= *(unsigned char *)(src + count);
		}
	}
	return (dest);
}
