/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:09:20 by acami             #+#    #+#             */
/*   Updated: 2021/04/17 22:41:25 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	str_pos;
	size_t	to_find_pos;
	size_t	to_find_len;

	to_find_pos = 0;
	str_pos = 0;
	to_find_len = ft_strlen(to_find);
	if (*to_find == '\0')
		return ((char *)str);
	while ((*(str + str_pos) != '\0') && (str_pos + to_find_len <= len))
	{
		to_find_pos = 0;
		while (*(str + str_pos + to_find_pos) == *(to_find + to_find_pos))
		{
			++to_find_pos;
			if (*(to_find + to_find_pos) == '\0')
			{
				return ((char *)str + str_pos);
			}
		}
		++str_pos;
	}
	return (NULL);
}
