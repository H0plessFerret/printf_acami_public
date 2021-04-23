/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 21:30:52 by acami             #+#    #+#             */
/*   Updated: 2021/04/17 21:32:51 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **head, t_list *new_elem)
{
	if (head == NULL)
		return ;
	if (*head == NULL)
	{
		*head = new_elem;
		return ;
	}
	new_elem->next = *head;
	*head = new_elem;
}
