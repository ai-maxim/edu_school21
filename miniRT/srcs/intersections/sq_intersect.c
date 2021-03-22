/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:03:25 by qdong             #+#    #+#             */
/*   Updated: 2021/03/21 17:15:28 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double			sq_intersect(t_ray ray, t_general *square)
{
	float	up;
	float	down;
	float	t1;
	float	t2;
	t_vec	cam_sq;
	t_vec	d;

	// printf("%f\n", square->side_size);
	cam_sq = substract_vec(ray.origin, square->direction);
	up = dot_product_vec(cam_sq, square->origin);
	down = dot_product_vec(square->direction, ray.origin);
	if (down == 0 || (up < 0 && down < 0) || (up > 0 && down))
		return (0);
	t1 = (-up / down);
	d = substract_vec(addit_vec(multiply_vec_num(ray.direction, t1), ray.origin), square->c1);
	t2 = square->side_size / 2;
	if (fabs(d.x) < t2 || fabs(d.y) < t2 || fabs(d.z) < t2)
		return (1);
	if (t1 < 0)
		return (0);
	return (t1);
}
