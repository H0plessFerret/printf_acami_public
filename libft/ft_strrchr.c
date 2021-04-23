/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:02:29 by acami             #+#    #+#             */
/*   Updated: 2021/04/17 15:30:19 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int character)
{
	char	*res;

	res = NULL;
	while (*str != '\0')
	{
		if (*str == character)
			res = (char *)str;
		++str;
	}
	if (character == '\0')
		res = (char *)str;
	return ((char *)res);
}
