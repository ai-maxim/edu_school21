/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:03:25 by qdong             #+#    #+#             */
/*   Updated: 2021/03/23 17:09:02 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double			sq_intersect(t_ray ray, t_objects *sq, double *t)
{
	float	up;
	float	down;
	float	t1;
	float	t2;
	t_vec	cam_sq;
	t_vec	d;

	printf("ASD");
	// printf("%f\n", sq->side_size);
	cam_sq = substract_vec(ray.origin, sq->direction);
	up = dpv(cam_sq, sq->origin);
	down = dpv(sq->direction, ray.origin);
	if (down == 0 || (up < 0 && down < 0) || (up > 0 && down))
		return (0);
	t1 = (-up / down);
	d = substract_vec(addit_vec(multip_vn(ray.direction, t1), ray.origin), sq->v1);
	t2 = sq->side_size / 2;
	if (fabs(d.x) < t2 || fabs(d.y) < t2 || fabs(d.z) < t2)
		return (1);
	if (t1 < 0)
		return (0);
	return (t1);
}
