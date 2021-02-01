/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:16:20 by qdong             #+#    #+#             */
/*   Updated: 2021/01/16 19:15:34 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_data
{
	int data;
}				t_data;

int		get_next_line(int fd, char **line);
int		chek_slesh_n(char **remain, char **line);
int		ft_strlen(const char *list);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char *line, char *list);
char	*ft_strchr(const char *line, int c);
int		free_rem(char *rem, int flag);

#endif
