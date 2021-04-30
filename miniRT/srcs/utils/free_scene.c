/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:48:55 by qdong             #+#    #+#             */
/*   Updated: 2021/04/22 18:04:59 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_cams(t_camera *cam)
{
	t_camera	*tmp;

	while (cam)
	{
		tmp = cam;
		cam = cam->next;
		free(tmp);
	}
}

void	free_lights(t_light *lgt)
{
	t_light	*tmp;

	while (lgt)
	{
		tmp = lgt;
		lgt = lgt->next;
		free(tmp);
	}
}

void	free_objs(t_objs *ob)
{
	t_objs	*tmp;

	while (ob)
	{
		tmp = ob;
		ob = ob->next;
		free(tmp->data);
		free(tmp);
	}
}

void	free_scene(t_scena *scena)
{
	free_cams(scena->cams);
	free_lights(scena->light);
	free_objs(scena->objs);
}
