/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:11 by qdong             #+#    #+#             */
/*   Updated: 2021/03/19 17:23:27 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_general	*new_cylinder(t_vec center, t_vec direction, float radius,
							float height)
{
	t_general	*cylinder;

	cylinder = malloc(sizeof(t_general));
	if (!cylinder)
		error_exit(-1);
	cylinder->center = center;
	cylinder->direction = direction;
	cylinder->radius = radius;
	cylinder->height = height;
//	cylinder->color = color;
	cylinder->type = 'c';
	return (cylinder);
}
