/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:57:57 by qdong             #+#    #+#             */
/*   Updated: 2021/03/22 11:33:26 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double			intersect(t_ray ray, t_general *objects)
{
	float	dist;
	float	result;

	result = 1000000;
	while (objects)
	{
		// if (objects->type == 'p')
		// {
		// 	dist = plane_intersect(ray, objects);
		// 	printf("TEST inter: %f\n", dist);
		// 	if (dist < 0.0001 || dist > 1000000)
		// 	{
		// 		objects = objects->next;
		// 		continue ;
		// 	}
		// 	result = dist;
		// 		// записать тип обекта
		// }

		// if (objects->type == 's')
		// {
		// 	dist = sfera_intersect(ray, objects);
		// 	printf("\n dist: %f", dist);
		// 	if (dist < 0.0001 || dist > 1000000)
		// 	{
		// 		objects = objects->next;
		// 		continue ;
		// 	}
		// 	result = dist;
		// 		// записать тип обекта
		// }

		// if (objects->type == 'q')
		// {
		// 	dist = sq_intersect(ray, objects);
		// 	if (dist < 0.0001 || dist > 1000000)
		// 	{
		// 		objects = objects->next;
		// 		continue ;
		// 	}
		// 	result = dist;
		// 		// записать тип обекта
		// }
		if (objects->type == 'c')
		{
			printf("\nobjects->type - %c\n", objects->type);
			dist = cy_intersect(ray, objects);
			if (dist < 0.0001 || dist > 1000000)
			{
				objects = objects->next;
				continue ;
			}
				result = dist;
				// записать тип обекта
		}
		//	if (objects->type == 't')
		// 	dist = tr_intersect(ray, objects);
		//	min(dist, dist < 0);
		objects = objects->next;
	}
	return (result);
}
