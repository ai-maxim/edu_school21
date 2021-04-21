/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:03:25 by qdong             #+#    #+#             */
/*   bdated: 2021/04/13 17:42:44 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_close	sq_intersect(t_vec *orig, t_vec *dir, void *data, double lim[2])
{
	t_vec	cam_pl;
	t_sq	*sq;
	t_tr	tr;
	t_close	cl;

	sq = data;
	sq->normal = normalize_vec(sq->normal);
	if (!(sq->normal.x == 0 && (sq->normal.y == 1 || sq->normal.y == -1)
			&& sq->normal.z == 0))
		sq->up = new_vector(0, 1, 0);
	else if (sq->normal.x == 0 && sq->normal.y == 1 && sq->normal.z == 0)
		sq->up = new_vector(0, 0, -1);
	else if (sq->normal.x == 0 && sq->normal.y == -1 && sq->normal.z == 0)
		sq->up = new_vector(0, 0, 1);
	sq->right = cross_product(sq->up, sq->normal);
	sq->left = cross_product(sq->right, sq->normal);
	tr.c1 = multip_vn(sq->right, sq->len);
	tr.c1 = addit_vec(tr.c1, sq->center);
	tr.c2 = multip_vn(sq->right, (-1) * sq->len);
	tr.c2 = addit_vec(tr.c2, sq->center);
	sq->d = multip_vn(sq->left, sq->len);
	sq->d = addit_vec(sq->d, sq->center);
	sq->e = multip_vn(sq->left, (-1) * sq->len);
	sq->e = addit_vec(sq->e, sq->center);
	tr.c3 = sq->d;
	tr.color = sq->color;
	cl = tr_intersect(orig, dir, &tr, lim);
	if (cl.t == INFINITY)
	{
		tr.c3 = sq->e;
		cl = tr_intersect(orig, dir, &tr, lim);
	}
	return (cl);
}
