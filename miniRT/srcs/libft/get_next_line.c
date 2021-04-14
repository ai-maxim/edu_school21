/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:07:22 by qdong             #+#    #+#             */
/*   Updated: 2021/04/09 13:59:10 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	free_rem(char *rem, int flag)
{
	if (rem)
		free(rem);
	return (flag);
}

int	this_while2(char **buf, int fd, char **remain, char **line)
{
	int		bytes;
	char	*tmp;

	bytes = read(fd, *buf, BUFFER_SIZE);
	while ((bytes))
	{
		if (bytes < 0)
			return (-1);
		tmp = *remain;
		(*buf)[bytes] = '\0';
		*remain = ft_strjoin_m(*remain, *buf);
		free_rem(tmp, 0);
		if ((chek_slesh_n(remain, line)) == 1)
			return (free_rem(*buf, 1));
		else if ((chek_slesh_n(remain, line)) == -1)
			return (free_rem(*buf, -1));
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			bytes;
	static char	*remain;
	int			j;

	*line = NULL;
	if (!line || BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (-1);
	bytes = chek_slesh_n(&remain, line);
	if ((bytes))
		return (bytes);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(buf))
		return (-1);
	j = this_while2(&buf, fd, &remain, line);
	if ((j))
		return (j);
	if (!remain)
		*line = ft_strdup("");
	else
		*line = ft_strdup(remain);
	free_rem(remain, 0);
	remain = NULL;
	return (free_rem(buf, 0));
}
