/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:02:11 by qdong             #+#    #+#             */
/*   Updated: 2021/03/17 17:08:12 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			plane_intersect(t_camera *cam, t_vec ray, t_general *plane)
{
	float	up;
	float	down;
	t_vec	cam_plane; //-x
	int		t;

	t = 0;
	cam_plane = substract_vec(plane->center, cam->origin);
//	printf("cam_plane = %f\ncenter = %f\nnormal = %f\n", cam_plane.x, cam_plane.y, cam_plane.z);
	up = dot_product_vec(cam_plane, plane->normal);
//	printf("up = %f\n", up);
	down = dot_product_vec(ray, plane->normal);
	if (down == 0)
		return (0);
	t = up / down;
	if (t < 0)
		return (0);
	return (t);
}
