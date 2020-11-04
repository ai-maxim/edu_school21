/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:11:06 by nmisfit           #+#    #+#             */
/*   Updated: 2020/11/04 14:03:33 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		d_len;
	size_t		s_len;
	size_t		i;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (size < d_len + 1)
		return (size + s_len);
	i = 0;
	while (i < size - d_len - 1 && src[i] != '\0')
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (d_len + s_len);
}
