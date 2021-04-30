/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:33 by qdong             #+#    #+#             */
/*   Updated: 2021/04/22 19:34:35 by qdong            ###   ########.fr       */
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

t_close	sp_intersect(t_vec *orig, t_vec *dir, void *data, double l[2])
{
	t_sp	*s;
	t_close	cl;

	s = data;
	init_zero(&cl);
	cl.normal = normalize_vec(*dir);
	s->oc = substract_vec(*orig, s->center);
	s->bch.x = dpv(s->oc, cl.normal);
	s->bch.y = dpv(s->oc, s->oc) - s->diam * s->diam * 0.25;
	s->bch.z = s->bch.x * s->bch.x - s->bch.y;
	if (s->bch.z < 0)
		return (cl);
	s->bch.z = sqrt(s->bch.z);
	s->t[0] = -1 * (s->bch.x + s->bch.z);
	s->t[1] = -1 * s->bch.x + s->bch.z;
	if (l[1] == 1)
	{
		s->t[0] = s->t[0] / lingth_vec(*dir);
		s->t[1] = s->t[1] / lingth_vec(*dir);
	}
	if (s->t[0] < s->t[1] && s->t[0] > 0 && s->t[0] > l[0] && s->t[0] < l[1])
		full_cl(&cl, s->t[0], s, orig);
	else if (s->t[1] > 0 && s->t[1] > l[0] && s->t[1] < l[1])
		full_cl(&cl, s->t[1], s, orig);
	return (cl);
}
