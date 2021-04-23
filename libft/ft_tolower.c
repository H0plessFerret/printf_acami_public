/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 18:40:39 by acami             #+#    #+#             */
/*   Updated: 2021/04/17 18:55:57 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int character_to_update)
{
	if ((character_to_update >= 'A')
		&& (character_to_update <= 'Z'))
		return (character_to_update + 32);
	return (character_to_update);
}
