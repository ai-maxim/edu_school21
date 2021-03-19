/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:46 by qdong             #+#    #+#             */
/*   Updated: 2021/03/17 13:56:55 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera		*new_camera(t_vec origin, t_vec direction, float fov)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (!cam)
		error_exit(-1);
	cam->origin = origin;
	cam->derection = direction;
	cam->fov = fov;
	return (cam);
}
