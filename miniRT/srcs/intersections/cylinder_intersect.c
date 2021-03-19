/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:26:02 by qdong             #+#    #+#             */
/*   Updated: 2021/03/19 18:28:00 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			cylinder_intersect(t_camera *cam, t_vec ray, t_general *cylinder)
{
	float	a;
	float	b;
	float	c;
	float	disc;
//	float	t;
	float	t1;
	float	t2;
	float	m;
	float	m1;
	t_vec	cam_cylinder;

	cam_cylinder = substract_vec(cylinder->center, cam->origin);
	//printf("cam_cylinder = %f\norigin =  %f\ndirection = %f\n", cam_cylinder.z, cam->origin.z, cylinder->direction.z);
	normalize_vec(cylinder->direction);
	a = dot_product_vec(ray, ray) - pow(dot_product_vec(ray, cylinder->direction), 2);
//	printf("a = %f\n", a);
	b = 2 * (dot_product_vec(ray, cam_cylinder) - dot_product_vec(ray, cylinder->direction) * dot_product_vec(cam_cylinder, cylinder->direction));
//	printf("b = %f\n", b);
	c = dot_product_vec(cam_cylinder, cam_cylinder) - pow(dot_product_vec(cam_cylinder, cylinder->direction), 2) - cylinder->radius * cylinder->radius;
	disc = (b * b) - (4 * a * c);
//	t = a * b;
	t1 = (-b + sqrt(disc)) / (2 * a);
	t2 = (-b - sqrt(disc)) / (2 * a);
	if (t1 < t2 && t1 > 0)
		return (t1);
	if (t2 < t1 && t2 > 0)
		return (t2);
	m = dot_product_vec(ray, cylinder->direction) * t1 + dot_product_vec(cam_cylinder, cylinder->direction);
	if (m >= 0 && m <= cylinder->height)
		return (t1);
	return (0);
}
