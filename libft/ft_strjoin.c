/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:16:36 by acami             #+#    #+#             */
/*   Updated: 2021/04/19 14:30:38 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *)malloc((s1_len + s2_len + 1)* sizeof(char));
	if (res == NULL)
		return (res);
	ft_strlcpy(res, s1, s1_len + 1);
	ft_strlcat(res + s1_len, s2, s2_len + 1);
	return (res);
}
