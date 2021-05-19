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

size_t	ft_wint_convertion(wint_t character, char *res)
{
	(void)res;
	if (character < 5)
	{
		return (0);
	}
	return (1);
}

size_t	ft_wstr_convertion(wchar_t *str, char *res)
{
	(void)res;
	if (*str < 5)
	{
		return (0);
	}
	return (1);
}
