/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:11:12 by acami             #+#    #+#             */
/*   Updated: 2021/04/19 14:31:38 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*func)(unsigned int, char))
{
	char	*res;
	size_t	count;

	if (str == NULL)
		return (NULL);
	res = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (res == NULL)
		return (res);
	count = 0;
	while (*(str + count) != '\0')
	{
		*(res + count) = (*func)(count, *(str + count));
		++count;
	}
	*(res + count) = '\0';
	return (res);
}
