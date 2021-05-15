/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:18:29 by acami             #+#    #+#             */
/*   Updated: 2021/05/11 19:18:29 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHFT_H
# define MATHFT_H

# include <inttypes.h>

typedef union u_128double	t_128double;

typedef union u_128double
{
	uint64_t	mask[2];
	long double	number;
};

#endif
