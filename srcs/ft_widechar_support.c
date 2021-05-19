/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widechar_support.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:55:30 by acami             #+#    #+#             */
/*   Updated: 2021/05/19 20:23:32 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

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
	if (char_len > len_allowed || char_len > MB_CUR_MAX)
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

size_t	ft_wstr_convertion(char *res, wchar_t *str, t_mask *mask)
{
	(void)res;
	(void)mask;
	if (*str < 5)
	{
		return (0);
	}
	return (1);
}
