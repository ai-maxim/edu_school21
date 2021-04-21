/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:33:29 by qdong             #+#    #+#             */
/*   Updated: 2021/04/21 11:59:15 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	cross_product(t_vec vec1, t_vec vec2)
{
	t_vec	ret;

	ret.x = vec1.y * vec2.z - vec1.z * vec2.y;
	ret.y = vec1.z * vec2.x - vec1.x * vec2.z;
	ret.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (ret);
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

t_vec	multip_vn(t_vec vec, double number)
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
