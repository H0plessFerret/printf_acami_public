/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:06:19 by acami             #+#    #+#             */
/*   Updated: 2021/04/23 15:31:57 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_print_type.h"
#include "../libft/libft.h"

int	ft_print_percent_sign(void *elem)
{
	return (write(1, "%", 1));
}

int	ft_print_char_n(char sym, int amount_of_times)
{
	int	count;

	count = 0;
	while (count < amount_of_times && write(1, &sym, 1))
		++count;
	return (count);
}
