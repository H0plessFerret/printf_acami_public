/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:21:25 by acami             #+#    #+#             */
/*   Updated: 2021/04/19 14:31:16 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_belongs_to_set(char sym, const char *set)
{
	while (*set != '\0')
	{
		if (sym == *set)
			return (1);
		++set;
	}
	return (0);
}

static void	ft_find_trim_size(size_t *left, size_t *right, char const *s1,
char const *set)
{
	char	not_empty;
	size_t	count;

	not_empty = 1;
	*left = 0;
	*right = 0;
	count = 0;
	if (*s1 == '\0')
		not_empty = 0;
	while (ft_belongs_to_set(*(s1 + count), set))
	{
		++(*left);
		++count;
	}
	if (*(s1 + count) == '\0')
		not_empty = 0;
	count = ft_strlen(s1) - 1;
	while (not_empty && ft_belongs_to_set(*(s1 + count), set))
	{
		++(*right);
		--count;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	left_len;
	size_t	right_len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	ft_find_trim_size(&left_len, &right_len, s1, set);
	res = (char *)malloc(ft_strlen(s1) - left_len - right_len + 1);
	if (res != NULL)
		ft_strlcpy(res, s1 + left_len, ft_strlen(s1) - left_len - right_len
			+ 1);
	return (res);
}
