/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:11:23 by acami             #+#    #+#             */
/*   Updated: 2021/04/19 18:18:56 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*res;
	size_t	count;

	if (str == NULL)
		return (NULL);
	if (ft_strlen(str + start) < len)
		len = ft_strlen(str + start);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (res);
	if (ft_strlen(str) <= start)
		return (res);
	count = 0;
	while (count < len)
	{
		*(res + count) = *(str + count + start);
		++count;
	}
	*(res + len) = '\0';
	return (res);
}
