/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:33 by qdong             #+#    #+#             */
/*   Updated: 2021/04/14 15:39:14 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_close	sp_intersect(t_vec *orig, t_vec *dir, void *data, double lim[2])
{
	double	b;
	double	c;
	double	discr;
	t_vec	cam_sp;
	t_sp	*sp;
	t_close	cl;
	double	t[2];

	sp = data;
	init_zero(&cl);
	cam_sp = substract_vec(*orig, sp->center);
	b = 2 * dpv(cam_sp, *dir);
	c = dpv(cam_sp, cam_sp) - (sp->diam * sp->diam * 0.25);
	discr = (b * b) - (4 * c);
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
		cl.obj_col = sp->color;
	}
	else
	{
		t[0] = ((b * (-1)) - sqrt(discr)) / 2;
		t[1] = ((b * (-1)) + sqrt(discr)) / 2;
		if (t[0] < t[1] && t[0] > 0)
		{
			cl.t = t[0];
			cl.obj_col = sp->color;
			cl.dot_inter = multip_vn(*dir, cl.t);
			cl.dot_inter = addit_vec(cl.dot_inter, *orig);
			cl.normal = substract_vec(cl.dot_inter, sp->center);
			cl.normal = normalize_vec(cl.normal);
		}
		else if (t[1] > 0)
		{
			cl.t = t[1];
			cl.obj_col = sp->color;
			cl.dot_inter = multip_vn(*dir, cl.t);
			cl.dot_inter = addit_vec(cl.dot_inter, *orig);
			cl.normal = substract_vec(cl.dot_inter, sp->center);
			cl.normal = normalize_vec(cl.normal);
		}
	}
	return (cl);
}
