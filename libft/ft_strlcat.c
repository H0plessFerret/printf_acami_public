/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:36:22 by acami             #+#    #+#             */
/*   Updated: 2021/04/19 18:20:26 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	dest_pos;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	dest_pos = 0;
	count = 0;
	while (*(dest + dest_pos) != '\0')
		++dest_pos;
	if (dest_len >= size)
		return (size + src_len);
	while ((*(src + count) != '\0') && (count < size - dest_len - 1))
	{
		*(dest + count + dest_pos) = *(src + count);
		++count;
	}
	*(dest + count + dest_pos) = '\0';
	return (dest_len + src_len);
}
