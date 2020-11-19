/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:09:34 by qdong             #+#    #+#             */
/*   Updated: 2020/11/04 21:57:51 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d == NULL && s == NULL)
		return (dest);
	if (s > d)
		ft_memcpy(dest, src, len);
	else
	{
		d = d + len - 1;
		s = s + len - 1;
		while (len--)
		{
			*d = *s;
			d--;
			s--;
		}
	}
	return (dest);
}
