/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:48:26 by qdong             #+#    #+#             */
/*   Updated: 2021/04/21 17:21:22 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *dest, int c, size_t len);
void				ft_bzero(void *s, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t len);
void				*ft_memccpy(void *dest, const void *src, int c, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memchr(const void *arr, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t len);
int					ft_strlen(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(char *s1, char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strnstr(const char *haystack,
						const char *needle, size_t len);
int					ft_atoi(char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *str, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *str, char const *set);
char				*ft_substr(char const *str, unsigned int start, size_t len);
char				*ft_itoa(int64_t n);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					get_next_line(int fd, char **line);
int					chek_slesh_n(char **remain, char **line);
int					free_rem(char *rem, int flag);
char				*ft_strjoin_m(char *s1, char *s2);
int					ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
double				ft_atof(char *str);

#endif
