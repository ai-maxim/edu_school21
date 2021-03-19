/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:51 by qdong             #+#    #+#             */
/*   Updated: 2021/03/18 14:49:09 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scena		*new_scena(t_camera *cams, t_general *objects)
{
	t_scena		*scena;

	scena = malloc(sizeof(t_scena));

	if (!scena)
		error_exit(-1);
	scena->cams = cams;
	scena->objects = objects;
	scena->widht = 0;
	scena->height = 0;
	return (scena);
}
