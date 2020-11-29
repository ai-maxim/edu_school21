/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:16:20 by qdong             #+#    #+#             */
/*   Updated: 2020/11/19 11:51:57 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef
# define
# define BUFF_SIZE 32

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int   get_next_line(int fd, char **line);
int   ft_strlen(char *list);
char  ft_strdup(char *last_line);
char  ft_strjoin(char *line, char *list);
char  ft_strchr(char *line, int c);

#endif
