/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isolate_specifiers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:08:01 by acami             #+#    #+#             */
/*   Updated: 2021/04/21 20:19:28 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../headers/ft_print_type.h"
#include "../headers/libft.h"

static size_t	ft_specifier_len(const char *format_spec)
{
	size_t	count;

	count = 0;
	return (count);
}

char	*ft_isolate_specifiers(const char **format_spec)
{
	char	*res;
	size_t	res_len;

	res_len = ft_specifier_len(*format_spec);
	res = (char *)malloc((res_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, *format_spec, res_len + 1);
	*format_spec += res_len;
	return (res);
}
