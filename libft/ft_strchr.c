/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:57:30 by acami             #+#    #+#             */
/*   Updated: 2021/04/17 15:28:12 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int character)
{
	while (*str != '\0')
	{
		if (*str == character)
			return ((char *)str);
		++str;
	}
	if (character == '\0')
		return ((char *)str);
	return (NULL);
}
