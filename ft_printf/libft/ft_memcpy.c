/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:16:49 by qdong             #+#    #+#             */
/*   Updated: 2020/11/04 21:59:23 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	d = NULL;
	s = NULL;
	d = dest;
	s = (unsigned char *)src;
	if (d == NULL && s == NULL)
		return (dest);
	i = 0;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
