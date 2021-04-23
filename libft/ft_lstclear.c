/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 21:48:13 by acami             #+#    #+#             */
/*   Updated: 2021/04/17 21:51:32 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void 	ft_lstclear(t_list **head, void (*del)(void *))
{
	t_list	*curr;

	if (head == NULL)
		return ;
	if (*head == NULL)
		return ;
	curr = *head;
	while (curr != NULL)
	{
		*head = curr->next;
		(*del)(curr->content);
		free(curr);
		curr = *head;
	}
}
