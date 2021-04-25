/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_mask_suplimentary.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:18:35 by acami             #+#    #+#             */
/*   Updated: 2021/04/25 19:12:21 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../libft/libft.h"

int	ft_mask_flags(const char *format_spec, t_mask *mask)
{
	char	curr_elem;
	int		count;

	count = 0;
	while (1)
	{
		curr_elem = *(format_spec + count);
		if (curr_elem == '-')
			mask->mask |= SPEC_MINUS;
		else if (curr_elem == '+')
			mask->mask |= SPEC_PLUS;
		else if (curr_elem == ' ')
		{
			if ((mask->mask & SPEC_PLUS) == 0)
				mask->mask |= SPEC_SPACE;
		}
		else if (curr_elem == '#')
			mask->mask |= SPEC_HASHTAG;
		else if (curr_elem == '0')
			mask->mask |= SPEC_ZERO;
		else
			break ;
		++count;
	}
	return (count);
}

int	ft_mask_width(const char *format_spec, t_mask *mask)
{
	char	curr_elem;
	int		count;

	count = 0;
	mask->width = -1;
	curr_elem = *format_spec;
	if (ft_isdigit(curr_elem))
	{
		mask->mask |= SPEC_NUM;
		mask->width = 0;
		while (ft_isdigit(curr_elem))
		{
			mask->width = 10 * mask->width + curr_elem - '0';
			++count;
			curr_elem = *(format_spec + count);
		}
	}
	else if (curr_elem == '*')
	{
		mask->mask |= SPEC_ASTERISK;
		++count;
	}
	return (count);
}

int	ft_mask_prescision(const char *format_spec, t_mask *mask)
{
	char	curr_elem;
	int		count;

	mask->prescision = -1;
	if (*format_spec != '.')
		return (0);
	count = 1;
	curr_elem = *(format_spec + count);
	if (curr_elem == '*')
	{
		mask->mask |= SPEC_DOTASTERISK;
		++count;
	}
	else if (ft_isdigit(curr_elem))
	{
		mask->mask |= SPEC_DOTNUM;
		mask->prescision = 0;
		while (ft_isdigit(curr_elem))
		{
			mask->prescision = 10 * mask->prescision + curr_elem - '0';
			++count;
			curr_elem = *(format_spec + count);
		}
	}
	else
		return (0);
	return (count);
}

int	ft_mask_length(const char *format_spec, t_mask *mask)
{
	if (*format_spec == 'h' && *(format_spec + 1) == 'h')
	{
		mask->mask |= SPEC_HH;
		return (2);
	}
	if (*format_spec == 'l' && *(format_spec + 1) == 'l')
	{
		mask->mask |= SPEC_LL;
		return (2);
	}
	if (*format_spec == 'h')
		mask->mask |= SPEC_H;
	else if (*format_spec == 'l')
		mask->mask |= SPEC_L;
	if ((mask->mask & SPEC_HAS_LENGTH) != 0)
		return (1);
	return (0);
}
