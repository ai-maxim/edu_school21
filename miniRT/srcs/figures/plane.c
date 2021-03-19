/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:16 by qdong             #+#    #+#             */
/*   Updated: 2021/03/19 17:52:59 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_general		*new_plane(t_vec center, t_vec normal)
{
	t_general		*plane;

	plane = malloc(sizeof(t_general));
	if (!plane)
		error_exit(-1);
	plane->center = center;
	plane->normal = normal;
//	plane->color = color;
	plane->type = 'p';
	return (plane);
}
