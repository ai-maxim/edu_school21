/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:16:20 by qdong             #+#    #+#             */
/*   Updated: 2021/01/11 18:10:56 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_struct
{
	int data;
}				t_struct;

int		get_next_line(int fd, char **line);
int		ft_strlen(char *list);
char	ft_strdup(char *last_line);
char	ft_strjoin(const char *line, const char *list);
char	ft_strchr(char *line, int c);

#endif
