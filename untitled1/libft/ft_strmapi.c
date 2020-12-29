/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:06:37 by qdong             #+#    #+#             */
/*   Updated: 2020/11/13 15:44:41 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	int				i;
	unsigned char	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (!(ret = (char *)malloc(sizeof(char) * (size) + 1)))
		return (0);
	i = 0;
	while (i < size)
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
