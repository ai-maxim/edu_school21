/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:05:27 by qdong             #+#    #+#             */
/*   Updated: 2021/04/09 13:46:14 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <math.h>

double	ft_atof(char *str)
{
	double	int_point;
	double	float_point;
	double	result;
	double	result_negative;
	char	*dot;

	int_point = (double)ft_atoi(str);
	float_point = 0;
	dot = ft_strchr(str, '.');
	if (dot)
	{
		++dot;
		float_point = (double)ft_atoi(dot);
		while (*dot >= 48 && *dot <= 57)
		{
			float_point /= (double)10;
			dot++;
		}
	}
	result = int_point + float_point;
	result_negative = (-1.0 * fabs(int_point) + float_point);
	if (int_point < 0)
		return (result_negative);
	return (result);
}
