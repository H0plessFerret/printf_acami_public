/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cbuff.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:53:57 by acami             #+#    #+#             */
/*   Updated: 2021/05/21 22:47:59 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CBUFF_H
# define FT_CBUFF_H

# include <inttypes.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_cbuffer	t_cbuffer;
struct s_cbuffer
{
	char	*data;
	size_t	size;
	size_t	curr_pos;
	int		associated_fd;
	bool	error_occured : 1;
};

t_cbuffer	*ft_init_cbuffer(size_t size, int associated_fd);
int			ft_close_cbuffer(t_cbuffer *cbuffer);
int			ft_insert_cbuffer(t_cbuffer *cbuffer, const char *str,
				size_t buffer_size);
int			ft_print_cbuffer(t_cbuffer *cbuffer);

#endif