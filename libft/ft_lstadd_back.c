/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 21:38:12 by acami             #+#    #+#             */
/*   Updated: 2021/04/17 22:48:04 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **head, t_list *new_elem)
{
	t_list	*curr;

	if (head == NULL)
		return ;
	if (*head == NULL)
	{
		*head = new_elem;
		return ;
	}
	curr = *head;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_elem;
}
