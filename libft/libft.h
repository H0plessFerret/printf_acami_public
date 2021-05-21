/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:44:07 by acami             #+#    #+#             */
/*   Updated: 2021/05/21 23:01:21 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

void	*ft_memset(void *mem, int val, size_t len);
void	ft_bzero(void *str, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int character, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memchr(const void *str, int character, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *str, int character);
char	*ft_strrchr(const char *str, int character);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);

int		ft_isalpha(int character_to_check);
int		ft_isdigit(int character_to_check);
int		ft_isalnum(int character_to_check);
int		ft_isascii(int character_to_check);
int		ft_isprint(int character_to_check);
int		ft_toupper(int character_to_update);
int		ft_tolower(int character_to_update);

char	*ft_strdup(const char *src);
void	*ft_calloc(size_t count, size_t size);

char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *str, char separator);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *str, char (*func)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **head, t_list *new_elem);
int		ft_lstsize(t_list *head);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_back(t_list **head, t_list *new_elem);
void	ft_lstdelone(t_list *head, void (*del)(void *));
void	ft_lstclear(t_list **head, void (*del)(void *));
void	ft_lstiter(t_list *head, void (*func)(void *));
t_list	*ft_lstmap(t_list *head, void *(*func)(void *), void (*del)(void *));

void	ft_strtoupper(char *str);

#endif