/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:52:29 by qdong             #+#    #+#             */
/*   Updated: 2021/03/17 14:51:40 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			colors(char *num, t_scena scena)
{
	char	**color;
	int		r;
	int		g;
	int		b;

	color = ft_split(num, ',');
	r = ft_atoi(color[0]);
	g = ft_atoi(color[1]);
	b = ft_atoi(color[2]);
	scena.color = (b * 256 * 256) + (g * 256) + r;
	return (scena.color);
}

// int			nums(char *num, t_scena scena)
// {
// 	char	**next;
// 	float	x;
// 	float	y;
// 	float	z;

// //	printf("%s", num);
// 	next = ft_split(num, ',');
// 	x = ft_atoi(next[0]);
// 	y = ft_atoi(next[1]);
// 	z = ft_atoi(next[2]);
// 	printf("%f,", x);
// 	printf("%f,", y);
// 	printf("%f", z);
// 	return (0);
//	}
