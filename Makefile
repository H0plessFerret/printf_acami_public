# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acami <acami@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 20:01:41 by acami             #+#    #+#              #
#    Updated: 2021/04/23 20:49:53 by acami            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
DEBUG		= ./debug/main.c
SRC_DIR		= ./srcs/
HEADERS		= ./headers/
SRC_F		= ft_print_till_percent.c ft_print.c
SRCS		= $(addprefix $(SRC_DIR), $(SRC_F))
OBJS		= $(SRCS:.c=.o)
TMPS		= $(SRCS:.c=.c~)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
BONUS_TMPS	= $(BONUS_SRCS:.c=.c~)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I $(HEADERS)
AR			= ar
ARFLAGS		= rc
LIBRAN		= ranlib
RM			= rm -f

.c.o:		
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@make -sC ./libft/ all
			$(AR) $(ARFLAGS) $(NAME) $(OBJS)
			$(LIBRAN) $(NAME)

bonus:		$(OBJS) $(BONUS_OBJS)
			$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(BONUS_OBJS)
			$(LIBRAN) $(NAME)

all:		$(NAME)

clean:		
			$(RM) $(TMPS) $(BONUS_TMPS)

fclean:		clean
			$(RM) $(OBJS) $(BONUS_OBJS)

re:			fclean all

.PHONY:		all clear fclean re