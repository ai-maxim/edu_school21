/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:56:25 by qdong             #+#    #+#             */
/*   Updated: 2021/04/22 18:22:10 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	substr_0(char const *str, unsigned int start,
					size_t len, char *str_mem)
{
	unsigned int	i;

	i = 0;
	while (str[start + i] && i < len)
	{
		str_mem[i] = str[start + i];
		i++;
	}
	str_mem[i] = '\0';
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char			*str_mem;

	if (!str)
		return (0);
	if (start >= (unsigned)ft_strlen(str))
	{
		str_mem = (char *)malloc(sizeof(char) * (len + 1));
		if (!(str_mem))
			return (NULL);
		str_mem[0] = '\0';
		return (str_mem);
	}
	if ((ft_strlen(str) - start) < len)
		len = ft_strlen(str) - start;
	str_mem = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str_mem))
		return (NULL);
	substr_0(str, start, len, str_mem);
	return (str_mem);
}
