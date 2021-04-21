/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:26:02 by qdong             #+#    #+#             */
/*   Updated: 2021/04/21 12:25:15 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	get_cy_normal(double m[], t_vec *p, t_vec *c, t_vec *v)
{
	t_vec	n;
	t_vec	vm;
	double	mm;

	mm = m[0];
	if (m[2] == 1)
		mm = m[1];
	vm = multip_vn(*v, mm);
	if (m[2] == 0)
	{
		n = substract_vec(*p, *c);
		n = substract_vec(n, vm);
	}
	else
	{
		n = addit_vec(*c, vm);
		n = substract_vec(n, *p);
	}
	n = normalize_vec(n);
	return (n);
}

void	fill_cyl_cl(t_close *cl, t_cy *cy, t_vec *orig, t_vec *dir)
{
	cl->obj_col = cy->color;
	cl->dot_inter = multip_vn(*dir, cl->t);
	cl->dot_inter = addit_vec(cl->dot_inter, *orig);
	cl->normal = get_cy_normal(cy->m, &cl->dot_inter, &cy->center, &cy->dir);
	invert_normal(&cl->normal, cl->dot_inter, orig);
}

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
	init_zero(&cl);
	if (lim[1] == 1)
		cl.t = 1;
	cam_cy = substract_vec(*orig, cy->center);
	cy->dir = normalize_vec(cy->dir);
	a = dpv(*dir, *dir) - pow(dpv(*dir, cy->dir), 2);
	b = 2 * (dpv(*dir, cam_cy) - dpv(*dir, cy->dir) * dpv(cam_cy, cy->dir));
	c = dpv(cam_cy, cam_cy) - pow(dpv(cam_cy, cy->dir), 2)
		- (cy->diam * cy->diam) * 0.25;
	discr = (b * b) - (4 * a * c);
	if (discr < 0)
		return (cl);
	t[0] = (-b - sqrt(discr)) / (2 * a);
	t[1] = (-b + sqrt(discr)) / (2 * a);
	if ((t[0] > 0 && t[1] > 0) || (t[0] < 0 && t[1] > 0))
	{
		cy->m[0] = dpv(*dir, cy->dir) * t[0] + dpv(cam_cy, cy->dir);
		cy->m[1] = dpv(*dir, cy->dir) * t[1] + dpv(cam_cy, cy->dir);
	}
	if (t[0] < t[1] && t[0] > 0 && cy->m[0] > 0 && cy->m[0] < cy->height
		&& (t[0] > lim[0] && t[0] < lim[1]))
	{
		cl.t = t[0];
		cy->m[2] = 0;
	}
	else if (t[1] > 0 && cy->m[1] > 0 && cy->m[1] < cy->height
		&& (t[1] > lim[0] && t[1] < lim[1]))
	{
		cl.t = t[1];
		cy->m[2] = 1;
	}
	else
		return (cl);
	if (lim[1] == INFINITY)
		fill_cyl_cl(&cl, cy, orig, dir);
	return (cl);
}
