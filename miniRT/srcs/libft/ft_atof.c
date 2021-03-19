/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:05:27 by qdong             #+#    #+#             */
/*   Updated: 2021/03/19 15:45:29 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <math.h>

// double		ft_atof(const char *str)
// {
// 	double	int_point;
// 	double	float_point;
// 	double	result;
// 	double	result_negative;
// 	char	*dot;

// 	int_point = ft_atoi(str);
// 	float_point = 0;
// 	dot = ft_strchr(str, '.');
// 	if (dot)
// 	{
// 		++dot;
// 		float_point = ft_atoi(dot);
// 		while (*dot >= 48 && *dot <= 57)
// 		{
// 			float_point /= (double)10;
// 			dot++;
// 		}
// 	}
// 	result = int_point + float_point;
//	result_negative = (-1.0 * fabs(int_point) + float_point);
// 	if (int_point < 0)
// 		return (result_negative);
// 	return (result);
// }



// int main()
// {
// 	char	*ptr = "21.01";

// 	printf("%.2f\n", ft_atof(ptr));
// 	printf("%f\n", fabs(-15.0));
// 	return (0);
// }
