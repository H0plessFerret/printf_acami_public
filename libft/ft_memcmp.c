/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:56:10 by acami             #+#    #+#             */
/*   Updated: 2021/04/19 15:37:45 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		if (*(unsigned char *)(s1 + count) != *(unsigned char *)(s2 + count))
		{
			return ((*(unsigned char *)(s1 + count))
				  - (*(unsigned char *)(s2 + count)));
		}
		++count;
	}
	return (0);
}
