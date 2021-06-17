/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:02:11 by qdong             #+#    #+#             */
/*   Updated: 2021/04/18 14:27:43 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	invert_normal(t_vec *norm, t_vec p, t_vec *o)
{
	t_vec	po;
	float	d;

	po = substract_vec(*o, p);
	po = normalize_vec(po);
	d = dpv(po, *norm);
	if (d < 0)
		*norm = multip_vn(*norm, -1);
}

t_close	pl_intersect(t_vec *orig, t_vec *dir, void *data, double lim[2])
{
	t_vec	cam_pl;
	t_pl	*pl;
	t_close	cl;
	double	t;

	pl = data;
	init_zero(&cl);
	pl->normal = normalize_vec(pl->normal);
	cam_pl = substract_vec(*orig, pl->center);
	if (dpv(*dir, pl->normal) == 0)
		return (cl);
	t = -1 * dpv(cam_pl, pl->normal) / dpv(*dir, pl->normal);
	if (t < lim[1] && t > lim[0])
	{
		cl.t = t;
		if (lim[1] == INFINITY)
		{
			cl.obj_col = pl->color;
			cl.dot_inter = multip_vn(*dir, t);
			cl.dot_inter = addit_vec(cl.dot_inter, *orig);
			cl.normal = pl->normal;
			invert_normal(&cl.normal, cl.dot_inter, orig);
		}
	}
	return (cl);
}
