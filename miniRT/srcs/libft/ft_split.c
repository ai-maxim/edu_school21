/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:20:28 by qdong             #+#    #+#             */
/*   Updated: 2021/04/10 17:22:01 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char const *s, char c)
{
	size_t		i;
	size_t		size;
	size_t		res;

	size = ft_strlen(s);
	i = 0;
	res = 0;
	while (i + 1 < size)
	{
		if (i == 0 && s[i] != c)
		{
			res++;
			++i;
			continue ;
		}
		if (s[i] == c && s[i + 1] != c)
			res++;
		++i;
	}
	return (res);
}

int	get_word(char const *s, int start, char c)
{
	int			end;

	end = start;
	while (s[end] != '\0')
	{
		if (s[end] == c)
			return (end);
		end++;
	}
	return (end);
}

void	clear(char **del, size_t count)
{
	size_t		i;

	i = 0;
	if (count > 0)
		while (i < count)
			free(del[i++]);
	free(del);
}

char	**ft_split(char const *s, char c)
{
	char	**segment;
	size_t	i;
	int		start;
	int		end;

	segment = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!s || !(segment))
		return (NULL);
	i = 0;
	start = 0;
	while (s[start])
	{
		if (s[start] != c)
		{
			end = get_word(s, start, c);
			segment[i] = ft_substr(s, start, end - start);
			if (!(segment[i++]))
				clear(segment, start);
			start = end;
			continue ;
		}
		start++;
	}
	segment[i] = NULL;
	return (segment);
}
