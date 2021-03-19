/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:41:18 by qdong             #+#    #+#             */
/*   Updated: 2021/03/18 16:52:47 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str1)
{
	char	*str;
	int		i;

	if (!str1)
		return ((char *)str1);
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(str1) + 1))))
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

int			chek_slesh_n(char **remain, char **line)
{
	char	*tmp;
	char	*b;

	b = NULL;
	tmp = *remain;
	if (*remain)
	{
		if ((b = ft_strchr(*remain, '\n')))
		{
			b[0] = '\0';
			if (!(*line = ft_strdup(*remain)))
				return (-1);
			b++;
			if (!(*remain = ft_strdup(b)))
				return (-1);
			return (free_rem(tmp, 1));
		}
	}
	return (0);
}

char		*ft_strjoin_m(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!(s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	if (!(i = 0) && s1)
	{
		while (s1[i] != '\0')
		{
			s3[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j] != '\0')
	{
		s3[i] = s2[j];
		j++;
		i++;
	}
	s3[i] = '\0';
	return (s3);
}

// char		*ft_strchr(const char *line, int c)
// {
// 	int		i;
// 	char	*tmp;

// 	tmp = (char *)line;
// 	i = 0;
// 	while (tmp[i] != (unsigned char)c && tmp[i] != '\0')
// 		i++;
// 	if (tmp[i] == (unsigned char)c)
// 		return ((char *)&tmp[i]);
// 	return (NULL);
// }
