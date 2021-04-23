/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:46:43 by acami             #+#    #+#             */
/*   Updated: 2021/04/17 16:52:41 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	divider;
	char		current_digit;
	char		num_started;

	num_started = 1;
	divider = -1000000000;
	if (n < 0)
		write(fd, "-", 1);
	else
		n = n * -1;
	while (divider != 0)
	{
		current_digit = n / divider % 10 + 48;
		divider = divider / 10;
		if ((current_digit != '0') || (num_started != 1) || (divider == 0))
		{
			num_started = 0;
			write(fd, &current_digit, 1);
		}
	}
}
