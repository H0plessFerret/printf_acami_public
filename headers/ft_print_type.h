/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:56:26 by acami             #+#    #+#             */
/*   Updated: 2021/04/25 18:49:56 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_TYPE_H
# define FT_PRINT_TYPE_H

# include "ft_printf.h"

int	ft_magic_write(char *str, size_t str_len, t_mask *mask);

int	ft_print_signed(va_list *arg_list, t_mask *mask);

int	ft_print_unsigned(va_list *arg_list, t_mask *mask);

int	ft_print_percent(va_list *arg_list, t_mask *mask);

int	ft_print_char(va_list *arg_list, t_mask *mask);

int	ft_print_string(va_list *arg_list, t_mask *mask);

int	ft_print_float(va_list *arg_list, t_mask *mask);

int	ft_print_pointer(va_list *arg_list, t_mask *mask);

int	ft_save_counter(va_list *arg_list, t_mask *mask);

/*
void	*ft_extract_info_from_arglist(va_list *arg_list, t_mask *mask, void *data)
{
	if ((mask->mask & SPEC_C) != 0)
		*(char *)data = (char)va_arg(*arg_list, int);
	else if ((mask->mask & SPEC_S) != 0)
		*(char **)data = va_arg(*arg_list, char *);
	else if ((mask->mask & SPEC_P) != 0)
		*(void **)data = va_arg(*arg_list, void *);
	else if ((mask->mask & SPEC_D_I) != 0)
		*(int *)data = va_arg(*arg_list, int);
	else if ((mask->mask & SPEC_IS_UNSIGNED) != 0)
		*(unsigned int *)data = va_arg(*arg_list, unsigned int);
	else if ((mask->mask & SPEC_IS_FLOAT) != 0)
		*(double *)data = va_arg(*arg_list, double);
	else if ((mask->mask & SPEC_N) != 0)
		*(int **)data = va_arg(*arg_list, int *);
	return (data);
}
*/

#endif
