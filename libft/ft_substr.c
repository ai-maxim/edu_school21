/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:56:25 by qdong             #+#    #+#             */
/*   Updated: 2020/11/16 18:56:20 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_substr(char const *str, unsigned int start, size_t len)
{
	char			*str_mem;
	unsigned int	i;

	if (!str)
		return (0);
	if (start >= ft_strlen(str))
	{
		if (!(str_mem = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		str_mem[0] = '\0';
		return (str_mem);
	}
	if ((ft_strlen(str) - start) < len)
		len = ft_strlen(str) - start;
	if (!(str_mem = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (str[start + i] && i < len)
	{
		str_mem[i] = str[start + i];
		i++;
	}
	str_mem[i] = '\0';
	return (str_mem);
}
