/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_till_percent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:55:52 by acami             #+#    #+#             */
/*   Updated: 2021/04/24 14:19:33 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_dprint_till_percent(int fd, const char **format_spec)
{
	int	count;

	count = 0;
	while (*(*format_spec + count) != '\0'
		&& *(*format_spec + count) != '%')
		++count;
	write(fd, *format_spec, count);
	*format_spec += count;
	return (count);
}
