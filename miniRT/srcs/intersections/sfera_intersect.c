/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfera_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:33 by qdong             #+#    #+#             */
/*   Updated: 2021/03/21 20:39:29 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double			sfera_intersect(t_ray ray, t_general *sfera)
{
	float	b;
	float	c;
	float	discr;
	float	dist_1;
	float	dist_2;
	t_vec	cam_sfera;

	dist_1 = 0;
	dist_2 = 0;
	cam_sfera = substract_vec(ray.origin, sfera->center);
	b = 2 * dot_product_vec(cam_sfera, ray.direction);
	c = dot_product_vec(cam_sfera, cam_sfera) - (sfera->radius * sfera->radius);
	discr = (b * b) - (4  * c);
	if (discr < 0)
		return (-1);
	dist_1 = ((b * (-1)) - sqrt(discr)) / 2;
	dist_2 = ((b * (-1)) + sqrt(discr)) / 2;
	if (dist_1 > dist_2 && dist_2 >= 0)
		return (dist_2);
	return (dist_1);
}
