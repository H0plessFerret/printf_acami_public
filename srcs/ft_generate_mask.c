/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_mask.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:04:49 by acami             #+#    #+#             */
/*   Updated: 2021/04/24 14:19:26 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../libft/libft.h"

extern int	g_width;
extern int	g_prescision;

static int	ft_mask_specifier(const char *format_spec, uint32_t *mask)
{
	char	curr_elem;

	curr_elem = *format_spec;
	if (curr_elem == 'd' || curr_elem == 'i')
		*mask |= SPEC_D_I;
	else if (curr_elem == 'u')
		*mask |= SPEC_U;
	else if (curr_elem == 'x')
		*mask |= SPEC_X;
	else if (curr_elem == 'X')
		*mask |= SPEC_X_UPPERCASE;
	else if (curr_elem == 'c')
		*mask |= SPEC_C;
	else if (curr_elem == 's')
		*mask |= SPEC_S;
	else if (curr_elem == 'p')
		*mask |= SPEC_P;
	else if (curr_elem == 'n')
		*mask |= SPEC_N;
	else if (curr_elem == '%')
		*mask |= SPEC_PERCENT;
	else
		return (ft_mask_specifier_extra(format_spec, mask));
	return (1);
}

static int	ft_mask_specifier_extra(const char *format_spec, uint32_t *mask)
{
	char	curr_elem;

	curr_elem = *format_spec;
	if (curr_elem == 'o')
		*mask |= SPEC_O;
	else if (curr_elem == 'f')
		*mask |= SPEC_F;
	else if (curr_elem == 'e')
		*mask |= SPEC_E;
	else if (curr_elem == 'g')
		*mask |= SPEC_G;
	else if (curr_elem == 'a')
		*mask |= SPEC_A;
	else
		return (-1);
	return (1);
}

uint32_t	ft_generate_mask(const char **format_spec)
{
	uint32_t	mask;
	int			elems_passed;

	mask = 0;
	elems_passed = 1;
	elems_passed += ft_mask_flags(*format_spec + elems_passed, &mask);
	elems_passed += ft_mask_width(*format_spec + elems_passed, &mask);
	elems_passed += ft_mask_prescision(*format_spec + elems_passed, &mask);
	elems_passed += ft_mask_length(*format_spec + elems_passed, &mask);
	if (ft_mask_specifier(*format_spec + elems_passed, &mask) == -1)
	{
		write(1, *format_spec, 1);
		mask = 0;
		g_width = -1;
		g_prescision = -1;
	}
	++(*format_spec);
	return (mask);
}
