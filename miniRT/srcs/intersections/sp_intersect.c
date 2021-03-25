/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:33 by qdong             #+#    #+#             */
/*   Updated: 2021/03/24 16:53:45 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			sp_intersect(t_ray ray, t_objs *sp, double *t)
{
	double	b;
	double	c;
	double	discr;
	t_vec	cam_sp;

	cam_sp = substract_vec(ray.origin, sp->center);
	b = 2 * dpv(cam_sp, ray.direction);
	c = dpv(cam_sp, cam_sp) - (sp->radius * sp->radius);
	discr = (b * b) - (4  * c);
	if (discr < 0)
	{
		t[0] = MAX_DIST;
		t[1] = MAX_DIST;
	}
	else if (discr * MAX_DIST > -1 && discr * MAX_DIST < 1)
	{
		t[0] = ((b * (-1))) / 2;
		t[1] = MAX_DIST;
	}
	else
	{
		t[0] = ((b * (-1)) - sqrt(discr)) / 2;
		t[1] = ((b * (-1)) + sqrt(discr)) / 2;
	}
}
