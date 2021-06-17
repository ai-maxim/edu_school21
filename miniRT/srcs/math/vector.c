/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:02:15 by qdong             #+#    #+#             */
/*   Updated: 2021/04/21 11:58:57 by qdong            ###   ########.fr       */
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
	double	result;

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

double	dpv(t_vec vec1, t_vec vec2)
{
	double	result;

	result = ((vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z));
	return (result);
}
