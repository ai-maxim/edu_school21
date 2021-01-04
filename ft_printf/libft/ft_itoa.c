/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:35:18 by qdong             #+#    #+#             */
/*   Updated: 2021/01/04 19:38:11 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int		len_int(int64_t n)
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

char			*ft_itoa(int64_t n)
{
	char		*s;
	int			i;

	i = len_int(n);
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

// int main(void)
// {
// 	int n;
// 	n = 2147483647;

// 	printf("%s", ft_itoa(n));
// 	return (0);
// }
