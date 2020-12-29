/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:33:36 by aarlena           #+#    #+#             */
/*   Updated: 2020/11/16 12:59:29 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Desktop/libft/ft_printf/libft/libft.h"

int		check_nonprintable(char str)
{
	char	nonprintable[6];
	int		i;

	nonprintable[0] = ' ';
	nonprintable[1] = '\t';
	nonprintable[2] = '\n';
	nonprintable[3] = '\v';
	nonprintable[4] = '\r';
	nonprintable[5] = '\f';
	i = 0;
	while (i < 6)
	{
		if (str == nonprintable[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_atoi(char *str)
{
	long	nbr;
	long	sign;
	long	i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (check_nonprintable(str[i]))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		i++;
	}
	return (nbr * sign);
}
