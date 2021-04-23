/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:48:34 by acami             #+#    #+#             */
/*   Updated: 2021/04/16 18:14:16 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int character_to_check)
{
	if ((character_to_check >= 'A') && (character_to_check <= 'Z'))
		return (1);
	if ((character_to_check >= 'a') && (character_to_check <= 'z'))
		return (1);
	return (0);
}
