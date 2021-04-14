/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:26:02 by qdong             #+#    #+#             */
/*   Updated: 2021/04/14 19:37:53 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_close	cy_intersect(t_vec *orig, t_vec *dir, void *data, double lim[2])
{
	t_vec	cam_cy;
	t_cy	*cy;
	t_close	cl;
	double	a;
	double	b;
	double	c;
	double	discr;
	double	t[2];

	cy = data;
	cam_cy = substract_vec(*dir, cy->center);
	normalize_vec(cy->dir);
	a = dpv(*dir, *dir) - pow(dpv(*dir, cy->dir), 2);
	b = 2 * (dpv(*dir, cam_cy) - dpv(*dir, cy->dir) * dpv(cam_cy, cy->dir));
	c = dpv(cam_cy, cam_cy) - pow(dpv(cam_cy, cy->dir), 2) - (cy->diam * cy->diam);
	discr = (b * b) - (4 * a * c);
	if (discr < 0)
	{
		cl.t = INFINITY;
		return (cl);
	}
	else if (discr * MAX_DIST > -1 && discr * MAX_DIST < 1)
	{
		t[0] = ((b * (-1))) / 2;
		t[1] = MAX_DIST;
		cl.t = t[0];
		cl.obj_col = cy->color;
	}
	else
	{
		t[0] = (-b + sqrt(discr)) / (2 * a);
		t[1] = (-b - sqrt(discr)) / (2 * a);
		if (t[0] < t[1] && t[0] > 0)
		{
			cl.t = t[0];
			cl.obj_col = cy->color;
		}
		else
		{
			cl.t = t[1];
			cl.obj_col = cy->color;
		}
	}
	return (cl);
}
