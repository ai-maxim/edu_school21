/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:07:22 by qdong             #+#    #+#             */
/*   Updated: 2020/11/19 09:36:58 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

int   ft_strlen(char *list)
{
  int i;

  i = 0;
  while (list[i] != '\0')
    i++;
  return (i);
}

char	*ft_strjoin(char *line, char *list)
{
	int		count;
	int		i;
	char	*array;

	count = 0;
	i = 0;
	array = (char *)malloc(((ft_strlen(line) +
					ft_strlen(list)) + 1) * sizeof(char));
	if (!array)
		return (NULL);
	while (line[count] != '\0')
	{
		array[count] = line[count];
		count++;
	}
	while (list[i] != '\0')
		array[count++] = list[i++];
	array[count] = '\0';
	return (array);
}

int	get_next_line(int fd, char **line)
{
    char buf[10 + 1];
    int     byte;

    *line = '\0';
	while ((byte = read(fd, buf, 10)));
    {
        buf[10] = '\0';
        *line = ft_strjoin(*line, buf);
    }
    return (0);
}
int main(void)
{
    int fd;
    char *line;

    fd = open("text.txt", O_RDONLY);
    get_next_line(fd, &line);
    printf("%s\n", line);
}
