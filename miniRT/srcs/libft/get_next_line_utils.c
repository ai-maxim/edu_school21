/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:41:18 by qdong             #+#    #+#             */
/*   Updated: 2021/04/10 17:45:41 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	char	*str;
	int		i;

	if (!str1)
		return ((char *)str1);
	str = (char *)malloc(sizeof(char) * (ft_strlen(str1) + 1));
	if (!(str))
		return (NULL);
	i = 0;
	while (str1[i] != '\0')
	{
		str[i] = str1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	chek_slesh_n(char **remain, char **line)
{
	char	*tmp;
	char	*b;

	b = NULL;
	tmp = *remain;
	if (*remain)
	{
		b = ft_strchr(*remain, '\n');
		if ((b))
		{
			b[0] = '\0';
			*line = ft_strdup(*remain);
			if (!(*line))
				return (-1);
			b++;
			*remain = ft_strdup(b);
			if (!(*remain))
				return (-1);
			return (free_rem(tmp, 1));
		}
	}
	return (0);
}

void	strjoin_0(char *s1, char *s2, char *s3)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s2[j] != '\0')
	{
		s3[i] = s2[j];
		j++;
		i++;
	}
	s3[i] = '\0';
}

char	*ft_strjoin_m(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	s3 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!(s3))
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i] != '\0')
		{
			s3[i] = s1[i];
			i++;
		}
	}
	strjoin_0(s1, s2, &s3[i]);
	return (s3);
}
