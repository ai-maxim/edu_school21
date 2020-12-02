/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:17:51 by qdong             #+#    #+#             */
/*   Updated: 2020/11/04 22:02:28 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned char	*ar1;
	unsigned char	*ar2;
	size_t			i;

	ar1 = (unsigned char *)s1;
	ar2 = (unsigned char *)s2;
	i = 0;
	while (len-- > 0)
	{
		if (ar1[i] != ar2[i])
			return (ar1[i] - ar2[i]);
		i++;
	}
	return (0);
}
