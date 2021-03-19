/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:33:29 by qdong             #+#    #+#             */
/*   Updated: 2021/03/17 17:05:24 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	basis_vec(float x, float y, float z)
{
	t_vec	i;
	t_vec	j;
	t_vec	k;

	i.x = x;
	j.y = y;
	k.z = z;
	k.z = i.x * j.y;

	return (k);
}

t_vec	cross_product(t_vec vec1, t_vec vec2)
{
	float	x;
	float	y;
	float	z;

	x = vec1.y * vec2.z - vec1.z * vec2.z;
	y = vec1.z * vec2.x - vec1.x * vec2.z;
	z = vec1.x * vec2.y - vec1.y * vec2.x;

	return (new_vector(x, y, z));
}

t_vec	normal(t_vec a, t_vec b, t_vec c)
{
	t_vec	normal;
	t_vec	edge1;
	t_vec	edge2;

	edge1 = substract_vec(b, a);
	edge2 = substract_vec(c, a);
	normal = cross_product(edge1, edge2);
	return (normal);
}
