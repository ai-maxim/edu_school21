/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:02:15 by qdong             #+#    #+#             */
/*   Updated: 2021/04/09 12:40:22 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	new_vector(double x, double y, double z)
{
	t_vec	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec	substract_vec(t_vec vec1, t_vec vec2)
{
	t_vec	result;

	result = new_vector(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
	return (result);
}

double	lingth_vec(t_vec vec)
{
	double result;

	result = sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
	return (result);
}

t_vec	normalize_vec(t_vec vec)
{
	double	lingth;

	lingth = lingth_vec(vec);
	vec.x /= lingth;
	vec.y /= lingth;
	vec.z /= lingth;

	return (vec);
}

// func scalyr proizvedenie too vectors dot_product_vec
double	dpv(t_vec vec1, t_vec vec2)
{
	double result;

	result = ((vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z));
	return (result);
}

t_vec		multip_vn(t_vec vec, double number)
{
	t_vec	result;

	result.x = vec.x * number;
	result.y = vec.y * number;
	result.z = vec.z * number;
	return (result);
}

t_vec	addit_vec(t_vec vec1, t_vec vec2)
{
	t_vec	result;

	result.x = vec1.x + vec2.x;
	result.y = vec1.y + vec2.y;
	result.z = vec1.z + vec2.z;
	return (result);
}

// t_vec multiply_vec(t_vec *vec, t_scena *obj)
// {
// 	t_vec result;

// 	result.x = vec->x * obj->object->type;
// 	result.y = vec->y * obj->object->type;
// 	result.z = vec->z * obj->object->type;
// 	return (result);
// }
