/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 21:38:59 by swautele          #+#    #+#             */
/*   Updated: 2022/02/24 19:27:02 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list_c
{
	char			*content;
	struct s_list_c	*next;
}	t_list_c;
typedef struct s_list_v{
	void			*content;
	struct s_list_v	*next;
}	t_list_v;
int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		*ft_memchr(const void *memoryblock, int searched, size_t size);
int			ft_memcmp(const void *p1, const void *p2, size_t n);
void		*ft_memcpy(void *destination, const void *source, size_t size);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *pointer, int value, size_t count);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *str, char c);
char		*ft_strchr(const char *str, int searched);
char		*ft_strdup(const char *src);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strjoin(const char *s1, const char *s2);
int			ft_strlcat(char *dest, const char *src, size_t size);
int			ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strmapi(const char *str, char (*f)(unsigned int, char));
int			ft_strncmp(const char *first, const char *second, size_t len);
char		*ft_strnstr(const char *str, const char *searched, size_t n);
char		*ft_strrchr(const char *str, int searched);
char		*ft_strtrim(const char *s1, const char *del);
char		*ft_substr(const char *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);
t_list_c	*ft_lstnew_c(void *content);
t_list_v	*ft_lstnew_v(void *content);
void		ft_lstadd_front_c(t_list_c **alst, t_list_c *new);
void		ft_lstadd_front_v(t_list_v **alst, t_list_v *new);
int			ft_lstsize_c(t_list_c *lst);
int			ft_lstsize_v(t_list_v *lst);
t_list_c	*ft_lstlast_c(t_list_c *lst);
t_list_v	*ft_lstlast_v(t_list_v *lst);
void		ft_lstadd_back_c(t_list_c **alst, t_list_c *new);
void		ft_lstadd_back_v(t_list_v **alst, t_list_v *new);
void		ft_lstdelone_c(t_list_c *lst, void (*del)(void*));
void		ft_lstdelone_v(t_list_v *lst, void (*del)(void*));
void		ft_lstclear_c(t_list_c **lst, void (*del)(void*));
void		ft_lstclear_v(t_list_v **lst, void (*del)(void*));
void		ft_lstiter_c(t_list_c *lst, void (*f)(void *));
void		ft_lstiter_v(t_list_v *lst, void (*f)(void *));
t_list_c	*ft_lstmap_c(t_list_c *lst, void *(*f)(void *), void (*del)(void *));
t_list_v	*ft_lstmap_v(t_list_v *lst, void *(*f)(void *), void (*del)(void *));

#endif
