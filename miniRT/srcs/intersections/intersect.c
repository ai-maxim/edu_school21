/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:57:57 by qdong             #+#    #+#             */
/*   Updated: 2021/03/24 16:49:09 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_objs			*intersect(t_ray ray, t_list *objects, double min, double max)
{
	double	closest_t; // дистанция до closest_obj
	double	t[2];
	t_objs *obj;
	t_objs *closest_obj; // Ближайший обьект в который попал луч

	closest_obj = NULL;
	closest_t = MAX_DIST;
	t[1] = MAX_DIST;
	while (objects)
	{
		obj = objects->content;
		if (obj->type == 'p')
			pl_intersect(ray, obj, t);
		if (obj->type == 's')
			sp_intersect(ray, obj, t);
		else if (obj->type == 'c')
			cy_intersect(ray, obj, t);
		else if (obj->type == 'q')
			sq_intersect(ray, obj, t);
		// else if (obj->type == 't')
		// 	tr_intersect(ray, obj, t);
		if (t[0] >= min && t[0] <= max && t[0] < closest_t)
		{
			closest_t = t[0];
			closest_obj = obj;
		}
		if (t[1] >= min && t[1] <= max && t[1] < closest_t)
		{
			closest_t = t[1];
			closest_obj = obj;
		}
		objects = objects->next;
	}
	return (closest_obj);
}
