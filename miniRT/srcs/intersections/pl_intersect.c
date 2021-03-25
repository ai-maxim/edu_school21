/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:02:11 by qdong             #+#    #+#             */
/*   Updated: 2021/03/23 15:03:57 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		pl_intersect(t_ray ray, t_objects *pl, double *t)
{
	double	a;
	double	b;
	t_vec	cam_pl;

	cam_pl = substract_vec(pl->center, ray.origin);
	a = dpv(cam_pl, pl->normal);
	b = dpv(ray.direction, pl->normal);
	// if (b == 0)
	// 	return (-1);
	t[0] = a / b;
	t[1] = MAX_DIST;
}
