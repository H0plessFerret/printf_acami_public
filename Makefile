# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acami <acami@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 20:01:41 by acami             #+#    #+#              #
#    Updated: 2021/04/28 16:13:44 by acami            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
DEBUG_SRC	= ./debug/main.c
SRC_DIR_LIB	= ./libft/
SRC_DIR		= ./srcs/
HEADERS		= ./headers/
SRC_F		= ft_dprint_till_percent.c  ft_find_corresponding_print.c  ft_generate_mask_suplimentary.c  ft_print_type_2.c  ft_printf.c       ft_pull_type_2.c \
ft_elem_write.c           ft_generate_mask.c             ft_print_type_1.c                ft_print_type_3.c  ft_pull_type_1.c ft_print_type_4.c  ft_print_type_5.c \
ft_generate_constructor.c
SRCS_F_LIB	= 
SRCS		= $(addprefix $(SRC_DIR), $(SRC_F))
SRCS_LIB	= $(addprefix $(SRC_DIR_LIB), $(SRCS_F_LIB))
OBJS		= $(SRCS:.c=.o)
OBJS_LIB	= $(SRCS_LIB:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
DEBUG_OBJS	= $(DEBUG_SRC:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g -I $(HEADERS)
AR			= ar
ARFLAGS		= rc
LIBRAN		= ranlib
RM			= rm -f
DEPENDS		= $(SRCS) $(HEADERS) Makefile

.c.o:		
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

debug:		$(OBJS) $(DEBUG_OBJS) $(DEPENDS)
			@make -sC ./libft/ all
			$(CC) $(OBJS) $(DEBUG_OBJS) ./libft/libft.a -o test.debug

$(NAME):	$(OBJS) $(OBJS_LIB) $(DEPENDS)
			@make -sC ./libft/ all
			$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(OBJS_LIB)
			$(LIBRAN) $(NAME)

bonus:		$(OBJS) $(BONUS_OBJS)
			$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(BONUS_OBJS)
			$(LIBRAN) $(NAME)

all:		$(NAME)

clean:		
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clear fclean re