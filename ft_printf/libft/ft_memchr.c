/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:17:43 by qdong             #+#    #+#             */
/*   Updated: 2020/11/04 22:24:40 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t len)
{
	unsigned char	*mas;
	size_t			i;

	mas = (unsigned char *)arr;
	i = 0;
	while (len--)
	{
		if (mas[i] == (unsigned char)c)
			return (&(mas[i]));
		i++;
	}
	return (NULL);
}
