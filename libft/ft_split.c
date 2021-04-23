/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:31:23 by acami             #+#    #+#             */
/*   Updated: 2021/04/19 14:36:12 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_is_sep(char sym, char separator)
{
	if ((sym == '\0') || (sym == separator))
		return (1);
	return (0);
}

static size_t	ft_space_needed(const char *str, char separator)
{
	size_t	space_required;

	space_required = 0;
	if (ft_strlen(str) == 0)
		return (0);
	if (ft_strlen(str) == 1)
	{
		if (ft_is_sep(*str, separator))
			return (0);
		return (1);
	}
	if (!ft_is_sep(*str, separator))
		++space_required;
	while (*str != '\0')
	{
		if (ft_is_sep(*str, separator) != ft_is_sep(*(str + 1), separator))
			++space_required;
		++str;
	}
	return (space_required / 2);
}

static size_t	ft_word_alloc(const char *str, char separator, char **res,
size_t curr_word)
{
	size_t	count;

	count = 0;
	while (!ft_is_sep(*(str + count), separator))
		++count;
	*(res + curr_word) = (char *)malloc(count + 1);
	if (*(res + curr_word) == NULL)
	{
		while (curr_word > 0)
		{
			--(curr_word);
			free(*(res + curr_word));
		}
		return (0);
	}
	return (1);
}

static size_t	ft_word_allocpy(const char *str, char separator, char **res,
size_t count)
{
	size_t	curr_word;
	size_t	str_pos;

	str_pos = 0;
	curr_word = 0;
	while (*(str + str_pos) != '\0')
	{
		if (!ft_is_sep(*(str + str_pos), separator))
		{
			if (ft_word_alloc(str + str_pos, separator, res, curr_word) == 0)
				return (0);
			count = 0;
			while (!ft_is_sep(*(str + str_pos), separator))
			{
				*(*(res + curr_word) + count) = *(str + str_pos);
				++str_pos;
				++count;
			}
			*(*(res + curr_word) + count) = '\0';
			++curr_word;
		}
		else
			++str_pos;
	}
	return (1);
}

char	**ft_split(char const *str, char separator)
{
	char	**res;

	if (str == NULL)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_space_needed(str, separator)
				+ 1));
	if (res == NULL)
		return (res);
	*(res + ft_space_needed(str, separator)) = NULL;
	if (ft_word_allocpy(str, separator, res, 0) == 0)
	{
		free(res);
		return (NULL);
	}
	return (res);
}
