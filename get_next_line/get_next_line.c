/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:07:22 by qdong             #+#    #+#             */
/*   Updated: 2021/01/11 18:44:29 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			get_next_line(int fd, char **line)
{
	char	buf;
	int		byte;
	int		BUFFER_SIZE;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
//	*line = '\0';
	byte = 0;
	while ((byte = read(fd, buf, BUFFER_SIZE)));
	{
		buf = '\0';
		*line = ft_strjoin(*line, &buf);
	}
	buf[byte] = '\0';
	return (0);
}

int main(void)
{
	int fd;
	char *line;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	return (0);
}
