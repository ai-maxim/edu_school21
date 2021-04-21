/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_movie.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:50:17 by qdong             #+#    #+#             */
/*   Updated: 2021/04/20 20:36:28 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	multip_matrix(t_vec *vec, t_matrix *matrix)
{
	t_vec	ret;

	ret.x = vec->x * matrix->right.x + vec->y * matrix->up.x + vec->z
		* matrix->forw.x + matrix->orig.x;
	ret.y = vec->x * matrix->right.y + vec->y * matrix->up.y + vec->z
		* matrix->forw.y + matrix->orig.y;
	ret.z = vec->x * matrix->right.z + vec->y * matrix->up.z + vec->z
		* matrix->forw.z + matrix->orig.z;
	return (ret);
}

t_matrix	look_at(t_camera *cams)
{
	t_matrix	matrix;
	t_vec		up_tmp;

	matrix.forw = cams->dir;
	matrix.orig = cams->orig;
	matrix.forw = normalize_vec(matrix.forw);
	if (!(matrix.forw.x == 0 && (matrix.forw.y == 1 || matrix.forw.y == -1)
			&& matrix.forw.z == 0))
		up_tmp = new_vector(0, 1, 0);
	else if (matrix.forw.x == 0 && matrix.forw.y == 1 && matrix.forw.z == 0)
		up_tmp = new_vector(0, 0, -1);
	else if (matrix.forw.x == 0 && matrix.forw.y == -1 && matrix.forw.z == 0)
		up_tmp = new_vector(0, 0, 1);
	matrix.right = cross_product(up_tmp, matrix.forw);
	matrix.right = normalize_vec(matrix.right);
	matrix.up = cross_product(matrix.forw, matrix.right);
	matrix.up = normalize_vec(matrix.up);
	return (matrix);
}

void	cam_go(t_vec *dot, t_camera *cams)
{
	t_matrix	matrix;
	t_vec		ray;

	matrix = look_at(cams);
	ray = multip_matrix(dot, &matrix);
	ray = substract_vec(ray, cams->orig);
	ray = normalize_vec(ray);
	*dot = ray;
}
