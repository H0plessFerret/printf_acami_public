/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 21:33:53 by acami             #+#    #+#             */
/*   Updated: 2021/04/17 21:37:16 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *head)
{
	int	res;

	res = 0;
	if (head == NULL)
		return (res);
	++res;
	while (head->next != NULL)
	{
		head = head->next;
		++res;
	}
	return (res);
}
