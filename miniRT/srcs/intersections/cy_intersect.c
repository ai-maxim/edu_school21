/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:26:02 by qdong             #+#    #+#             */
/*   Updated: 2021/04/22 19:24:55 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_m(t_cy *cy, double *t)
{
	if (cy->m[0] < -0.0000001 || cy->m[0] > cy->height)
		t[0] = INFINITY;
	if (cy->m[1] < -0.0000001 || cy->m[1] > cy->height)
		t[1] = INFINITY;
}

double	cy_closest(double *t, double *lim)
{
	if (t[0] >= lim[0] && t[0] <= lim[1])
	{
		if (t[1] >= lim[0] && t[1] <= lim[1])
		{
			if (t[0] < t[1])
				return (t[0]);
			else
				return (t[1]);
		}
		return (t[0]);
	}
	else if (t[1] >= lim[0] && t[1] <= lim[1])
		return (t[1]);
	else if (lim[1] == 1)
		return (1);
	else
		return (INFINITY);
}

double	get_t(t_cy *cy, t_vec *orig, t_vec *dir)
{
	t_vec	cam_cy;

	cam_cy = substract_vec(*orig, cy->center);
	cy->dir = normalize_vec(cy->dir);
	cy->a = dpv(*dir, *dir) - pow(dpv(*dir, cy->dir), 2);
	cy->b = 2 * (dpv(*dir, cam_cy) - dpv(*dir, cy->dir) * dpv(cam_cy, cy->dir));
	cy->c = dpv(cam_cy, cam_cy) - pow(dpv(cam_cy, cy->dir), 2)
		- (cy->diam * cy->diam) * 0.25;
	cy->discr = (cy->b * cy->b) - (4 * cy->a * cy->c);
	if (cy->discr < -0.0000001)
		return (INFINITY);
	cy->t[0] = (-cy->b - sqrt(cy->discr)) / (2 * cy->a);
	cy->t[1] = (-cy->b + sqrt(cy->discr)) / (2 * cy->a);
	cy->m[0] = dpv(*dir, cy->dir) * cy->t[0] + dpv(cam_cy, cy->dir);
	cy->m[1] = dpv(*dir, cy->dir) * cy->t[1] + dpv(cam_cy, cy->dir);
	return (0);
}

t_close	cy_intersect(t_vec *orig, t_vec *dir, void *data, double lim[2])
{
	t_cy	*cy;
	t_close	cl;

	cy = data;
	init_zero(&cl);
	if (lim[1] == 1)
		cl.t = 1;
	if (get_t(cy, orig, dir) == INFINITY)
		return (cl);
	check_m(cy, cy->t);
	cl.t = cy_closest(cy->t, lim);
	if (!cl.t)
		return (cl);
	fill_cyl_cl(&cl, cy, orig, dir);
	return (cl);
}
