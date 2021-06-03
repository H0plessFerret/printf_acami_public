/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widechar_support.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:55:30 by acami             #+#    #+#             */
/*   Updated: 2021/05/31 17:42:05 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../libft/libft.h"

static size_t	ft_wcharlen(wchar_t character)
{
	if ((int64_t)character < 128LL)
		return (1);
	else if ((int64_t)character < 2048LL)
		return (2);
	else if ((int64_t)character < 65536LL)
		return (3);
	else if ((int64_t)character < 2097152LL)
		return (4);
	return (0);
}

size_t	ft_wint_convertion(char *res, wint_t character, int32_t len_allowed)
{
	size_t	char_len;

	char_len = ft_wcharlen((wchar_t)character);
	if (char_len > (size_t)len_allowed || char_len > (size_t)MB_CUR_MAX)
		return (0);
	if (char_len == 1)
		res[0] = character;
	else
	{
		if (char_len == 2)
			res[0] = ((character >> 6) & 31) | 192;
		else
		{
			if (char_len == 3)
				res[0] = ((character >> 12) & 15) | 224;
			else
			{
				res[0] = ((character >> 18) & 7) | 240;
				res[1] = ((character >> 12) & 63) | 128;
			}
			res[char_len - 2] = ((character >> 6) & 63) | 128;
		}
		res[char_len - 1] = (character & 63) | 128;
	}
	return (char_len);
}

static size_t	ft_wstrlen(wchar_t *str)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		count += ft_wcharlen(*str);
		++str;
	}
	return (count);
}

size_t	ft_wstr_convertion(char **res, wchar_t *str, int32_t max_len)
{
	size_t	str_pos;
	size_t	count;
	size_t	max_str_len;
	size_t	curr_sym_len;
	char	buff[4];

	max_str_len = ft_wstrlen(str);
	if (max_len != NOT_SET && (size_t)max_len < max_str_len)
		max_str_len = max_len;
	*res = malloc(max_str_len);
	if (*res == NULL)
		return (0);
	str_pos = 0;
	count = 0;
	curr_sym_len = ft_wint_convertion(buff, str[str_pos], max_str_len - count);
	while (curr_sym_len != 0)
	{
		ft_memcpy(*res + count, buff, 4);
		count += curr_sym_len;
		++str_pos;
		curr_sym_len = ft_wint_convertion(buff, str[str_pos],
				max_str_len - count);
	}
	return (count);
}
