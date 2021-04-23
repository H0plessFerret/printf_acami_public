/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:04:00 by acami             #+#    #+#             */
/*   Updated: 2021/04/17 18:18:32 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_is_ignorable(char sym)
{
	if ((sym != '\n') && (sym != ' ') && (sym != '\t')
		&& (sym != '\v') && (sym != '\r') && (sym != '\f'))
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while (ft_is_ignorable(*str))
		++str;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	else if (*str == '+')
		++str;
	while ((*str >= '0') && (*str <= '9'))
	{
		result = result * 10 + (*str - '0') * sign;
		++str;
	}
	return (result);
}
