/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:02:11 by qdong             #+#    #+#             */
/*   Updated: 2021/03/22 11:25:20 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		plane_intersect(t_ray ray, t_general *plane)
{
	float	a;
	float	b;
	t_vec	cam_plane;
	double	t;

	t = 0;
	cam_plane = substract_vec(plane->center, ray.origin);
	a = dot_product_vec(cam_plane, plane->normal);
	b = dot_product_vec(ray.direction, plane->normal);
	if (b == 0)
		return (-1);
	t = a / b;
	if (t < 0)
		return (-1);
	return (t);
}
