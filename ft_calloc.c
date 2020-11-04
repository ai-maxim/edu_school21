/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:30:33 by qdong             #+#    #+#             */
/*   Updated: 2020/11/04 22:07:33 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char *s;

	s = (unsigned char*)malloc(count * size);
	if (!s)
		return (NULL);
	ft_bzero(s, count * size);
	return ((void *)s);
}
