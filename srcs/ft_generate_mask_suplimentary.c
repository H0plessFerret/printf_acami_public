/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_mask_suplimentary.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:18:35 by acami             #+#    #+#             */
/*   Updated: 2021/04/24 14:19:10 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../libft/libft.h"

extern int	g_width;
extern int	g_prescision;

int	ft_mask_flags(const char *format_spec, uint32_t *mask)
{
	char	curr_elem;
	int		count;

	count = 0;
	while (1)
	{
		curr_elem = *(format_spec + count);
		if (curr_elem == '-')
			*mask |= SPEC_MINUS;
		else if (curr_elem == '+')
			*mask |= SPEC_PLUS;
		else if (curr_elem == ' ')
		{
			if ((*mask & SPEC_PLUS) == 0)
				*mask |= SPEC_SPACE;
		}
		else if (curr_elem == '#')
			*mask |= SPEC_HASHTAG;
		else if (curr_elem == '0')
			*mask |= SPEC_ZERO;
		else
			break ;
		++count;
	}
	return (count);
}

int	ft_mask_width(const char *format_spec, uint32_t *mask)
{
	char	curr_elem;
	int		count;

	count = 0;
	g_width = -1;
	curr_elem = *format_spec;
	if (ft_isdigit(curr_elem))
	{
		*mask |= SPEC_NUM;
		g_width = 0;
	}
	while (ft_isdigit(curr_elem))
	{
		g_width = 10 * g_width + curr_elem - '0';
		++count;
		curr_elem = *(format_spec + count);
	}
	if (curr_elem == '*')
	{
		*mask |= SPEC_ASTERISK;
		++count;
	}
	return (count);
}

int	ft_mask_prescision(const char *format_spec, uint32_t *mask)
{
	char	curr_elem;
	int		count;

	g_prescision = -1;
	if (*format_spec != '.')
		return (0);
	count = 1;
	curr_elem = *(format_spec + count);
	if (curr_elem == '*')
	{
		*mask |= SPEC_DOTASTERISK;
		++count;
	}
	else
	{
		*mask |= SPEC_DOTNUM;
		g_prescision = 0;
	}
	while (ft_isdigit(curr_elem))
	{
		g_prescision = 10 * g_prescision + curr_elem - '0';
		++count;
		curr_elem = *(format_spec + count);
	}
	return (count);
}

int	ft_mask_length(const char *format_spec, uint32_t *mask)
{
	if (*format_spec == 'h' && *(format_spec + 1) == 'h')
	{
		*mask |= SPEC_HH;
		return (2);
	}
	if (*format_spec == 'l' && *(format_spec + 1) == 'l')
	{
		*mask |= SPEC_LL;
		return (2);
	}
	if (*format_spec == 'h')
		*mask |= SPEC_H;
	else if (*format_spec == 'l')
		*mask |= SPEC_L;
	else if (*format_spec == 'j')
		*mask |= SPEC_J;
	else if (*format_spec == 'z')
		*mask |= SPEC_Z;
	else if (*format_spec == 't')
		*mask |= SPEC_T;
	else if (*format_spec == 'L')
		*mask |= SPEC_L_UPPERCASE;
	if ((*mask & SPEC_HAS_LENGTH) != 0)
		return (1);
	return (0);
}
