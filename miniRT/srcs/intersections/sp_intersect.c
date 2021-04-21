/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:33 by qdong             #+#    #+#             */
/*   Updated: 2021/04/18 18:42:17 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	full_cl(t_close *cl, double t, t_sp	*sp, t_vec *orig)
{
	t_vec	dir;

	dir = cl->normal;
	cl->t = t;
	cl->obj_col = sp->color;
	cl->dot_inter = multip_vn(dir, cl->t);
	cl->dot_inter = addit_vec(cl->dot_inter, *orig);
	cl->normal = substract_vec(cl->dot_inter, sp->center);
	cl->normal = normalize_vec(cl->normal);
}

t_close	sp_intersect(t_vec *orig, t_vec *dir, void *data, double lim[2])
{
	t_vec	oc;
	t_vec	bch;
	double	t[2];
	t_sp	*sp;
	t_close	cl;

	sp = data;
	init_zero(&cl);
	cl.normal = normalize_vec(*dir);
	oc = substract_vec(*orig, sp->center);
	bch.x = dpv(oc, cl.normal);
	bch.y = dpv(oc, oc) - sp->diam * sp->diam * 0.25;
	bch.z = bch.x * bch.x - bch.y;
	if (bch.z < 0)
		return (cl);
	bch.z = sqrt(bch.z);
	t[0] = -1 * (bch.x + bch.z);
	t[1] = -1 * bch.x + bch.z;
	if (lim[1] == 1)
	{
		t[0] = t[0] / lingth_vec(*dir);
		t[1] = t[1] / lingth_vec(*dir);
	}
	if (t[0] < t[1] && t[0] > 0 && t[0] > lim[0] && t[0] < lim[1])
		full_cl(&cl, t[0], sp, orig);
	else if (t[1] > 0 && t[1] > lim[0] && t[1] < lim[1])
		full_cl(&cl, t[1], sp, orig);
	return (cl);
}

// void	full_cl(t_close *cl, double t, t_sp	*sp, t_vec *orig)
// {
// 	t_vec dir;

// 	dir = cl->normal;
// 	cl->t = t;
// 	cl->obj_col = sp->color;
// 	cl->dot_inter = multip_vn(dir, cl->t);
// 	cl->dot_inter = addit_vec(cl->dot_inter, *orig);
// 	cl->normal = substract_vec(cl->dot_inter, sp->center);
// 	cl->normal = normalize_vec(cl->normal);
// }

// t_close	sp_intersect(t_vec *orig, t_vec *dir, void *data, double lim[2])
// {
// 	t_vec	bcd;
// 	t_vec	cam_sp;
// 	t_sp	*sp;
// 	t_close	cl;
// 	double	t[2];

// 	sp = data;
// 	init_zero(&cl);
// 	cl.normal = *dir;
// 	cam_sp = substract_vec(*orig, sp->center);
// 	bcd.x = 2 * dpv(cam_sp, *dir);
// 	bcd.y = dpv(cam_sp, cam_sp) - (sp->diam * sp->diam * 0.25);
// 	bcd.z = (bcd.x* bcd.x) - (4 * bcd.y);
// 	if (bcd.z < 0)
// 		return (cl);
// 	else if (bcd.z * MAX_DIST > -1 && bcd.z * MAX_DIST < 1)
// 	{
// 		t[0] = ((bcd.x * (-1))) / 2;
// 		t[1] = MAX_DIST;
// 		cl.t = t[0];
// 		cl.obj_col = sp->color;
// 	}
// 	else
// 	{
// 		t[0] = ((bcd.x * (-1)) - sqrt(bcd.z)) / 2;
// 		t[1] = ((bcd.x * (-1)) + sqrt(bcd.z)) / 2;
// 		if (t[0] < t[1] && t[0] > 0)
// 			full_cl(&cl, t[0], sp, orig);
// 		else if (t[1] > 0)
// 			full_cl(&cl, t[1], sp, orig);
// 	}
// 	return (cl);
// }
