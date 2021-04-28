# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acami <acami@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/17 15:17:44 by acami             #+#    #+#              #
#    Updated: 2021/04/28 15:48:51 by acami            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
HEADERS		= ./
SRCS		= ft_atoi.c       ft_isalpha.c    ft_itoa.c       ft_memcpy.c     ft_putendl_fd.c ft_strchr.c     ft_strlcpy.c    ft_strnstr.c    ft_tolower.c \
ft_bzero.c      ft_isascii.c    ft_memccpy.c    ft_memmove.c    ft_putnbr_fd.c  ft_strdup.c     ft_strlen.c     ft_strrchr.c    ft_toupper.c \
ft_calloc.c     ft_isdigit.c    ft_memchr.c     ft_memset.c     ft_putstr_fd.c  ft_strjoin.c    ft_strmapi.c    ft_strtrim.c \
ft_isalnum.c    ft_isprint.c    ft_memcmp.c     ft_putchar_fd.c ft_split.c      ft_strlcat.c    ft_strncmp.c    ft_substr.c \
ft_strtoupper.c
OBJS		= $(SRCS:.c=.o)
TMPS		= $(SRCS:.c=.c~)
BONUS_SRCS	= ft_lstadd_back.c        ft_lstclear.c           ft_lstiter.c            ft_lstmap.c             ft_lstsize.c \
ft_lstadd_front.c       ft_lstdelone.c          ft_lstlast.c            ft_lstnew.c
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