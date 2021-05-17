/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:03:40 by acami             #+#    #+#             */
/*   Updated: 2021/05/17 20:08:27 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHFT_H
# define MATHFT_H

# include <inttypes.h>
# include <stdbool.h>
# include <stdlib.h>

# ifndef SD_PRECISION
#  define SD_PRECISION	10000
# endif

/*
# define 	BYTE_TO_BINARY_PATTERN 	"<%c%c%c%c%c%c%c%c>"
# define 	BYTE_TO_BINARY(byte)	\
(byte & 0x80 ? '1' : '0'), \
(byte & 0x40 ? '1' : '0'), \
(byte & 0x20 ? '1' : '0'), \
(byte & 0x10 ? '1' : '0'), \
(byte & 0x08 ? '1' : '0'), \
(byte & 0x04 ? '1' : '0'), \
(byte & 0x02 ? '1' : '0'), \
(byte & 0x01 ? '1' : '0') 

# define	BYTE_TO_BINARY_R(byte)	\
(byte & 0x01 ? '1' : '0'), \
(byte & 0x02 ? '1' : '0'), \
(byte & 0x04 ? '1' : '0'), \
(byte & 0x08 ? '1' : '0'), \
(byte & 0x10 ? '1' : '0'), \
(byte & 0x20 ? '1' : '0'), \
(byte & 0x40 ? '1' : '0'), \
(byte & 0x80 ? '1' : '0') 
*/

typedef union u_80double	t_80double;
typedef struct s_80dblmask	t_80dblmask;
typedef struct s_strdouble	t_strdouble;

struct s_80dblmask{
	uint64_t	mant : 63;
	uint64_t	inte : 1;
	uint64_t	exp : 15;
	uint64_t	sig : 1;
	uint64_t	trash : 48;
};

union	u_80double
{
	t_80dblmask	mask;
	long double	num;
};

struct s_strdouble
{
	char		*number;
	uint64_t	num_len;
	int32_t		power;
	int32_t		last_sig_digit;
	bool		is_negative : 1;
};

// Create a new t_strdouble entity
// Use this instead of manually allocating a new element
t_strdouble	*ft_sd_init(void);

// Free all allocated memory for an element
void		*ft_free_sd(t_strdouble *number);

// Change allocated memory size to new_len
// Returns true if allocation was successful
bool		ft_resize_number(t_strdouble *number, uint64_t new_len);

// Convert int64_t to t_stringdouble
t_strdouble	*ft_i_to_sd(int64_t number);

// Convert long double to t_stringdouble
t_strdouble	*ft_ld_to_sd(long double number);
// Creates a copy of a number amd returns it
t_strdouble	*ft_copy_sd(t_strdouble *number);
void		ft_round_to_pres(t_strdouble *number, uint32_t precision);
char		*ft_sd_to_scientific(t_strdouble *number, uint32_t precision);
char		*ft_sd_to_floating(t_strdouble *number, uint32_t precision);
long double	ft_sd_to_ld(t_strdouble *number);

// Calculate minimum length of a new number being created by + or -
uint64_t	ft_newnum_len_basic(t_strdouble *a, t_strdouble *b);
// Check if 1 more digit needs to be added when adding two numbers
uint64_t	ft_newnum_overflow_basic(t_strdouble *a, t_strdouble *b);
// Check if 1 less digit needs to be added when substracting two numbers
uint64_t	ft_newnum_underflow_basic(t_strdouble *a, t_strdouble *b);

// Returns 0 if a == b, negative number if a < b, positive number if a > b
int16_t		ft_compare_sd(t_strdouble *a, t_strdouble *b);
// Returns 0 if abs(a) == abs(b), negative number if abs(a) < abs(b),
// positive number if abs(a) > abs(b)
int16_t		ft_compare_abs_sd(t_strdouble *a, t_strdouble *b);

// Add two digits in a and b in position of 10 ^ (curr_power),
// and save the extra to carry_over
int16_t	ft_add_digits(t_strdouble *a, t_strdouble *b, int64_t curr_power,
				int16_t *carry_over);
t_strdouble	*ft_add_sd(t_strdouble *a, t_strdouble *b);

t_strdouble	*ft_substract_sd(t_strdouble *a, t_strdouble *b);
t_strdouble	*ft_multiply_sd(t_strdouble *a, t_strdouble *b);
t_strdouble	*ft_divide_sd(t_strdouble *a, t_strdouble *b);
t_strdouble	*ft_log_sd(t_strdouble *number);
t_strdouble	*ft_power_sd(t_strdouble *number, t_strdouble *power);
t_strdouble	*ft_abs_sd(t_strdouble *number);

#endif
