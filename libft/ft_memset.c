/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:17:26 by acami             #+#    #+#             */
/*   Updated: 2021/04/19 15:38:17 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *mem, int val, size_t len)
{
	while (len != 0)
	{
		--len;
		*(unsigned char *)(mem + len) = (unsigned char)val;
	}
	return (mem);
}
