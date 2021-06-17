/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:49:21 by qdong             #+#    #+#             */
/*   Updated: 2020/11/04 22:00:53 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;
	int		lenstr;

	lenstr = (int)ft_strlen(s);
	tmp = (char *)s;
	i = lenstr;
	while (lenstr != -1)
	{
		lenstr--;
		if (tmp[i] == c)
			return (&tmp[i]);
		i--;
	}
	return (NULL);
}
