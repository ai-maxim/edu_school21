/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:35:18 by qdong             #+#    #+#             */
/*   Updated: 2020/11/17 11:12:01 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len_int(int n)
{
	int			len;

	len = 0;
	if (n <= 0)
		len = len + 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int		minint(int n, char *s)
{
	if (n == -2147483648)
	{
		s[1] = '2';
		n = -147483648;
	}
	return (n);
}

char			*ft_itoa(int n)
{
	char		*s;
	int			i;

	i = len_int(n);
	if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_bzero(s, i + 1);
	n = minint(n, s);
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	else if (n == 0)
	{
		s[0] = '0';
		return (s);
	}
	while (n != 0)
	{
		i--;
		s[i] = n % 10 + '0';
		n = n / 10;
	}
	return (s);
}
