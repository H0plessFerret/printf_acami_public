# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acami <acami@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 20:01:41 by acami             #+#    #+#              #
#    Updated: 2021/05/21 22:06:44 by acami            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
DEBUG_SRC	= ./debug/main.c
SRC_DIR_LIB	= ./libft/
SRC_DIR		= ./srcs/
HEADERS		= ./headers/
SRC_F		= ft_elem_write.c \
ft_find_corresponding_print.c \
ft_generate_mask.c \
ft_generate_mask_suplimentary.c \
ft_generate_strconst.c \
ft_generate_strconst_suplimentary.c \
ft_print_till_percent.c \
ft_print_type_1.c \
ft_print_type_2.c \
ft_print_type_3.c \
ft_print_type_4.c \
ft_print_type_5.c \
ft_printf.c \
ft_pull_type.c \
ft_widechar_support.c\
ft_cbuff.c
SRCS_F_LIB	= ft_atoi.c       ft_isalpha.c    ft_itoa.c       ft_memcpy.c     ft_putendl_fd.c ft_strchr.c     ft_strlcpy.c    ft_strnstr.c    ft_tolower.c \
ft_bzero.c      ft_isascii.c    ft_memccpy.c    ft_memmove.c    ft_putnbr_fd.c  ft_strdup.c     ft_strlen.c     ft_strrchr.c    ft_toupper.c \
ft_calloc.c     ft_isdigit.c    ft_memchr.c     ft_memset.c     ft_putstr_fd.c  ft_strjoin.c    ft_strmapi.c    ft_strtrim.c \
ft_isalnum.c    ft_isprint.c    ft_memcmp.c     ft_putchar_fd.c ft_split.c      ft_strlcat.c    ft_strncmp.c    ft_substr.c \
ft_strtoupper.c
SRCS		= $(addprefix $(SRC_DIR), $(SRC_F))
SRCS_LIB	= $(addprefix $(SRC_DIR_LIB), $(SRCS_F_LIB))
OBJS		= $(SRCS:.c=.o)
OBJS_LIB	= $(SRCS_LIB:.c=.o)
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

$(NAME):	$(OBJS) $(OBJS_LIB) $(DEPENDS)
			@make -sC ./libft/ all
			$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(OBJS_LIB)
			$(LIBRAN) $(NAME)

bonus:		$(NAME)

all:		$(NAME)

clean:		
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

debug:		$(OBJS) $(DEBUG_OBJS) $(OBJS_LIB) $(DEPENDS)
			$(CC) $(OBJS) $(DEBUG_OBJS) $(OBJS_LIB) ./libft/libft.a -o test.debug


.PHONY:		all clear fclean re