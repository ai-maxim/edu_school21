/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:03:25 by qdong             #+#    #+#             */
/*   Updated: 2021/03/19 20:47:28 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			sq_intersect(t_vec oridin, t_ray ray, t_general *square)
{
	float	up;
	float	down;
	float	t1;
	float	t2;
	t_vec	cam_sq;
	t_vec	d;

	cam_sq = substract_vec(square->center, ray.direction);
	up = dot_product_vec(cam_sq, square->normal);
	down = dot_product_vec(ray.direction, square->normal);
	if (down == 0 || (up < 0 && down < 0) || (up > 0 && down))
		return (1);
	t1 = -up / down;
	d = substract_vec(addit_vec(multiply_vec_num(ray.direction, t1), oridin), square->c);
	t2 = square->height / 2;
	if (fabs(d.x) > t2 || fabs(d.y) > t2 || fabs(d.z) > t2)
		return (0);
	if (t1 < 0)
		return (0);
	return (t1);
}

// if (down == 0)
	// 	return (0);
	// t = up / down;
	// if (t < 0)
	// 	return (0);
	// return (t);
