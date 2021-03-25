/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:26:02 by qdong             #+#    #+#             */
/*   Updated: 2021/03/23 15:03:36 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double			cy_intersect(t_ray ray, t_objects *cy, double *t)
{
	double	a;
	double	b;
	double	c;
	double	disc;
//	double	t;
	double	t1;
	double	t2;
	double	m;
	double	m1;
	t_vec	cam_cy;

	cam_cy = substract_vec(ray.direction, cy->origin);
	normalize_vec(cy->direction);
	a = dpv(ray.direction, ray.direction) - pow(dpv(ray.direction, cy->direction), 2);
	b = 2 * (dpv(ray.direction, cam_cy) - dpv(ray.direction, cy->direction) * dpv(cam_cy, cy->direction));
	c = dpv(cam_cy, cam_cy) - pow(dpv(cam_cy, cy->direction), 2) - (cy->radius * cy->radius);
	disc = (b * b) - (4 * a * c);
//	t = a / b;
	t1 = (-b + sqrt(disc)) / (2 * a);
	t2 = (-b - sqrt(disc)) / (2 * a);
	if (t1 < t2 && t1 > 0)
		return (t1);
	if (t2 < t1 && t2 > 0)
		return (t2);
	m = dpv(ray.direction, cy->direction) * t1 + dpv(cam_cy, cy->direction);
	if (m >= 0 && m <= cy->height)
		return (t1);
	return (-1);
}
