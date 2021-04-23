/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:40:30 by acami             #+#    #+#             */
/*   Updated: 2021/04/16 17:46:21 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (((*(s1 + count) != '\0') || (*(s2 + count) != '\0')) && (count < n))
	{
		if (*(s1 + count) != *(s2 + count))
			return ((unsigned char)(*(s1 + count))
				  - (unsigned char)(*(s2 + count)));
		++count;
	}
	return (0);
}
