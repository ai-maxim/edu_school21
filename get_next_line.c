/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:07:22 by qdong             #+#    #+#             */
/*   Updated: 2020/11/20 12:00:03 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>


int	get_next_line(int fd, char **line)
{
	char	buff(10 + 1);

	read(fd, buff, 10)
	return (0);
}
int main()
{
	char	*line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	printf("%d\n", fd);
}
