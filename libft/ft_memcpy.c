/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:32:26 by acami             #+#    #+#             */
/*   Updated: 2021/04/19 15:38:03 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if ((dest == NULL) && (src == NULL))
		return (NULL);
	while (n != 0)
	{
		--n;
		*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
	}
	return (dest);
}
