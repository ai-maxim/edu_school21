/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tr_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:34:48 by qdong             #+#    #+#             */
/*   Updated: 2021/04/18 14:27:24 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	tr_intersect_1(t_vec *dir, void *data, t_perem *p)
{
	p->v1 = substract_vec(((t_tr *)data)->c2, ((t_tr *)data)->c1);
	p->v2 = substract_vec(((t_tr *)data)->c3, ((t_tr *)data)->c1);
	p->vec = cross_product(*dir, p->v2);
	p->det = dpv(p->v1, p->vec);
}

void	tr_intersect_2(t_perem *p, void *data, t_vec *orig)
{
	p->c = 1.0 / p->det;
	p->tvec = substract_vec(*orig, ((t_tr *)data)->c1);
	p->a = dpv(p->tvec, p->vec) * p->c;
}

void	init_arg(t_vec *orig, t_vec *dir, double lim[2], t_arg *arg)
{
	arg->dir = dir;
	arg->lim0 = lim[0];
	arg->lim1 = lim[1];
	arg->orig = orig;
}

void	tr_intersect_3(void *data, t_perem p, t_close *cl, t_arg *arg)
{
	p.t = dpv(p.v2, p.tvec) * p.c;
	if (p.t < arg->lim1 && p.t > arg->lim0)
	{
		cl->t = p.t;
		if (arg->lim1 == INFINITY)
		{
			cl->obj_col = ((t_tr *)data)->color;
			cl->dot_inter = multip_vn(*arg->dir, p.t);
			cl->dot_inter = addit_vec(cl->dot_inter, *arg->orig);
			cl->normal = cross_product(p.v1, p.v2);
			cl->normal = normalize_vec(cl->normal);
			invert_normal(&cl->normal, cl->dot_inter, arg->orig);
		}
	}
}

t_close	tr_intersect(t_vec *orig, t_vec *dir, void *data, double lim[2])
{
	t_perem	p;
	t_close	cl;
	t_arg	arg;

	init_zero(&cl);
	tr_intersect_1(dir, data, &p);
	if (fabs(p.det) < 0.00001)
		return (cl);
	tr_intersect_2(&p, data, orig);
	if (p.a < 0 || p.a > 1)
		return (cl);
	p.tvec = cross_product(p.tvec, p.v1);
	p.b = dpv(*dir, p.tvec) * p.c;
	if (p.b < 0 || p.a + p.b > 1)
		return (cl);
	init_arg(orig, dir, lim, &arg);
	tr_intersect_3(data, p, &cl, &arg);
	return (cl);
}
