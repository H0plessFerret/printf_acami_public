/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 21:52:25 by acami             #+#    #+#             */
/*   Updated: 2021/04/17 22:50:06 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *head, void *(*func)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*curr;

	res = NULL;
	while (head != NULL)
	{
		curr = ft_lstnew((*func)(head->content));
		if (curr == NULL)
		{
			ft_lstclear(&res, (*del));
			return (NULL);
		}
		ft_lstadd_back(&res, curr);
		head = head->next;
	}
	return (res);
}
