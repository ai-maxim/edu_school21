/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:35:18 by qdong             #+#    #+#             */
/*   Updated: 2021/01/08 21:08:36 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len_int(int64_t n)
{
	int			len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*nsi(char *s, int64_t n, int i)
{
	while (n != 0)
	{
		if (n > 0)
		{
			i--;
			s[i] = n % 10 + '0';
			n = n / 10;
		}
		else
		{
			s[i] = n % 10 + '0';
			n = n / 10;
		}
	}
	return (s);
}

char			*s_mall(int64_t n, char *s, int i)
{
	if (n < 0)
	{
		if (!(s = (char *)malloc(sizeof(char) * (i + 2))))
			return (NULL);
	}
	else
	{
		if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
			return (NULL);
	}
	return (s);
}

char			*ft_itoa(int64_t n)
{
	char		*s;
	int			i;

	s = NULL;
	i = len_int(n);
	s = s_mall(n, s, i);
	ft_bzero(s, i + 1);
	if (n < 0)
	{
		ft_bzero(s, i + 2);
		s[0] = '-';
		n *= -1;
	}
	else if (n == 0)
	{
		s[0] = '0';
		return (s);
	}
	else
		ft_bzero(s, i + 1);
	s = nsi(s, n, i);
	return (s);
}
