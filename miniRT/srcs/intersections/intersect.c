/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:57:57 by qdong             #+#    #+#             */
/*   Updated: 2021/03/19 20:00:36 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double			intersect(t_vec oridin, t_vec ray, t_general *objects)
{
	float	dist;

	while (objects)
	{
		dist = plane_intersect(oridin, ray, );
		if (objects->type == 'p')
			return (dist);
		min(dist, dist < 0);
		objects->type;
	}
	return (-1);
}
