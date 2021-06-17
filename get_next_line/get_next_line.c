/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:07:22 by qdong             #+#    #+#             */
/*   Updated: 2021/01/17 17:42:13 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int free_rem(char *rem, int flag)
{
	if (rem)
		free(rem);
	return (flag);
}

int			this_while(char **buf, int fd, char **remain, char **line)
{
	char		*tmp;
	int			bytes;

	while ((bytes = read(fd, *buf, BUFFER_SIZE)))
	{
		if (bytes < 0)
			return (-1);
		tmp = *remain;
		(*buf)[bytes] = '\0';
		*remain = ft_strjoin(*remain, *buf);
		free_rem(tmp, 0);
		if ((chek_slesh_n(&*remain, line)) == 1)
			return (free_rem(*buf, 1));
		else if ((chek_slesh_n(&*remain, line)) == -1)
			return (free_rem(*buf, -1));
	}
	return (0);
}

int			this_while2(char *buf, int fd, char *remain, char **line)
{
	int			bytes;
	char		*tmp;

	while ((bytes = read(fd, buf, BUFFER_SIZE)))
	{
		if (bytes < 0)
			return (-1);
		tmp = remain;
		buf[bytes] = '\0';
		remain = ft_strjoin(remain, buf);
		free_rem(tmp, 0);
		if ((chek_slesh_n(&remain, line)) == 1)
			return (free_rem(buf, 1));
		else if ((chek_slesh_n(&remain, line)) == -1)
			return (free_rem(buf, -1));
	}
	return (0);
}


int				get_next_line(int fd, char **line)
{
	char		*buf;
	int			bytes;
	// char		*tmp;
	static char	*remain;
	int j;

	*line = NULL;
	if (!line || BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (-1);
	if ((bytes = chek_slesh_n(&remain, line)))
		return (bytes);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);

	if ((j = this_while2(buf, fd, remain, line)))
		return (j);
//	return (this_while(&buf, fd, &remain, line));
	// while ((bytes = read(fd, buf, BUFFER_SIZE)))
	// {
	// 	if (bytes < 0)
	// 		return (-1);
	// 	tmp = remain;
	// 	buf[bytes] = '\0';
	// 	remain = ft_strjoin(remain, buf);
	// 	free_rem(tmp, 0);
	// 	if ((chek_slesh_n(&remain, line)) == 1)
	// 		return (free_rem(buf, 1));
	// 	else if ((chek_slesh_n(&remain, line)) == -1)
	// 		return (free_rem(buf, -1));
	// }
	if (!remain)
		*line = ft_strdup("");
	else
		*line = ft_strdup(remain);
	free_rem(remain, 0);
	remain = NULL;
//	sleep(1000);
	return (free_rem(buf, 0));
}

int main(void)
{
	int fd;
	int i;
	char *line;

	fd = open("text.txt", O_RDONLY);
	while ((i = get_next_line(fd, &line)))
	{
		printf("%d %s\n", i, line);
		free(line);
	}
	printf("%d %s\n", i, line);
	free(line);
	return (0);
}
