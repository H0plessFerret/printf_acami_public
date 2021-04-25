/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_mask.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:04:49 by acami             #+#    #+#             */
/*   Updated: 2021/04/25 15:43:45 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../libft/libft.h"

static int	ft_mask_specifier(const char *format_spec, t_mask *mask)
{
	char	curr_elem;

	curr_elem = *format_spec;
	if (curr_elem == 'd' || curr_elem == 'i')
		mask->mask |= SPEC_D_I;
	else if (curr_elem == 'u')
		mask->mask |= SPEC_U;
	else if (curr_elem == 'x')
		mask->mask |= SPEC_X;
	else if (curr_elem == 'X')
		mask->mask |= SPEC_X_UPPERCASE;
	else if (curr_elem == 'c')
		mask->mask |= SPEC_C;
	else if (curr_elem == 's')
		mask->mask |= SPEC_S;
	else if (curr_elem == 'p')
		mask->mask |= SPEC_P;
	else if (curr_elem == 'n')
		mask->mask |= SPEC_N;
	else if (curr_elem == '%')
		mask->mask |= SPEC_PERCENT;
	else
		return (ft_mask_specifier_extra(format_spec, mask));
	return (1);
}

static int	ft_mask_specifier_extra(const char *format_spec, t_mask *mask)
{
	char	curr_elem;

	curr_elem = *format_spec;
	if (curr_elem == 'o')
		mask->mask |= SPEC_O;
	else if (curr_elem == 'f')
		mask->mask |= SPEC_F;
	else if (curr_elem == 'e')
		mask->mask |= SPEC_E;
	else if (curr_elem == 'g')
		mask->mask |= SPEC_G;
	else if (curr_elem == 'a')
		mask->mask |= SPEC_A;
	else
		return (-1);
	return (1);
}

t_mask	*ft_generate_mask(const char **format_spec, t_mask *mask)
{
	int		elems_passed;

	mask->mask = 0;
	elems_passed = 1;
	elems_passed += ft_mask_flags(*format_spec + elems_passed, mask);
	elems_passed += ft_mask_width(*format_spec + elems_passed, mask);
	elems_passed += ft_mask_prescision(*format_spec + elems_passed, mask);
	elems_passed += ft_mask_length(*format_spec + elems_passed, mask);
	if (ft_mask_specifier(*format_spec + elems_passed, mask) == -1)
	{
		write(1, *format_spec, 1);
		elems_passed = 1;
		mask->mask = 0;
		mask->width = -1;
		mask->prescision = -1;
	}
	*format_spec += elems_passed;
	return (mask);
}
