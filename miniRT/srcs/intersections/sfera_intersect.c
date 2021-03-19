/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfera_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:33 by qdong             #+#    #+#             */
/*   Updated: 2021/03/19 17:41:17 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			sfera_intersect(t_camera *cam, t_vec ray, t_general *sfera)
{
//	float	a;
	float	b;
	float	c;
	float	discr;
	float	dist_1;
	float	dist_2;
	t_vec	cam_sfera;

	dist_1 = 0;
	dist_2 = 0;
	cam_sfera = substract_vec(sfera->center, cam->origin);
//	printf("cam_plane = %f\ncenter = %f\nnormal = %f\n", cam_sfera.x, cam_sfera.y, cam_sfera.z);
//	a = dot_product_vec(cam_sfera, cam_sfera);
	b = 2 * dot_product_vec(cam_sfera, ray);
	c = dot_product_vec(cam_sfera, cam_sfera) - (sfera->radius * sfera->radius);
	discr = (b * b) - (4 * c);
	if (discr < 0)
		return (0);
	dist_1 = ((b * (-1)) - sqrt(discr)) / 2;
	dist_2 = ((b * (-1)) + sqrt(discr)) / 2;
	if (dist_1 > 0)
		return (1);
	return (0);
}
