/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 16:08:10 by qdong             #+#    #+#             */
/*   Updated: 2021/01/10 20:05:38 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_i(uint64_t n, int alph_size)
{
	int		len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / alph_size;
		len++;
	}
	return (len);
}

char		*itoa_base2(uint64_t n, char *alph)
{
	int		alph_size;
	int		len;
	char	str[25];

	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (ft_strdup(str));
	}
	alph_size = ft_strlen(alph);
	len = len_i(n, alph_size);
	str[len--] = '\0';
	while (n)
	{
		str[len--] = alph[n % alph_size];
		n = n / alph_size;
	}
	return (ft_strdup(str));
}
