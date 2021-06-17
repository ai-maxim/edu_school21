/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:46:58 by qdong             #+#    #+#             */
/*   Updated: 2020/11/04 22:23:33 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	d;
	unsigned char	*str;
	size_t			i;

	d = (unsigned char)c;
	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = d;
		i++;
	}
	return (str);
}
