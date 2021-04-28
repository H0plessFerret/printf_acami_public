/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:27:25 by acami             #+#    #+#             */
/*   Updated: 2021/04/29 00:27:25 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_print_type.h"
#include "../headers/ft_pull_type.h"
#include "../libft/libft.h"

int	ft_print_char(va_list *arg_list, t_mask *mask)
{
	char	c[2];

	c[0] = ft_pull_char(arg_list, &(mask->length_modifiers));
	c[1] = '\0';
	return (ft_elem_write(c, 1, mask));
}

int	ft_print_string(va_list *arg_list, t_mask *mask)
{
	char	*str;

	str = ft_pull_pointer(arg_list, &(mask->length_modifiers));
	if (str == NULL)
	{
		if (mask->prescision > 5)
			str = "(null)";
		else
			str = "";
	}
	else if (mask->prescision != NOT_SET)
		return (ft_elem_write(str, mask->prescision, mask));
	return (ft_elem_write(str, ft_strlen(str), mask));
}

int	ft_print_pointer(va_list *arg_list, t_mask *mask)
{
	void	*ptr;
	char	*str;

	ptr = ft_pull_pointer(arg_list, &(mask->length_modifiers));
	if (ptr == NULL)
		str = "(null)";
	else
		str = ft_put_unsignednbr_base((uintmax_t)ptr, 16, mask);
	return (ft_elem_write(str, ft_strlen(str), mask));
}

int	ft_save_counter(va_list *arg_list, t_mask *mask)
{
	intmax_t	*to_write;

	to_write = ft_pull_pointer(arg_list, &(mask->length_modifiers));
	*to_write = (intmax_t)mask->symbols_printed;
	return (0);
}
