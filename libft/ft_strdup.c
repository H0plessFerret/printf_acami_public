/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 18:43:44 by acami             #+#    #+#             */
/*   Updated: 2021/04/16 18:48:21 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*res;
	size_t	count;
	size_t	src_len;

	count = 0;
	src_len = ft_strlen(src);
	res = (char *)malloc(src_len + 1);
	if (res == NULL)
		return (res);
	while (count <= src_len)
	{
		*(res + count) = *(src + count);
		++count;
	}
	return (res);
}
