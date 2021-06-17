/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_intersect2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:14:47 by qdong             #+#    #+#             */
/*   Updated: 2021/04/22 19:15:28 by qdong            ###   ########.fr       */
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
	n = substract_vec(*p, *c);
	n = substract_vec(n, vm);
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
