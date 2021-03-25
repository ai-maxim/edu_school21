/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:26:54 by qdong             #+#    #+#             */
/*   Updated: 2021/03/24 23:43:18 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		parse_c(char *line, t_scena *scena)
{
	char	**array;
	char	**num;
	char	**num1;
	t_camera	*new_cam;
	t_camera	*tmp;

	new_cam = malloc(sizeof(t_camera));
	new_cam->next = NULL;
	new_cam->prev = NULL;
	array = ft_split(line + 1, ' ');
	new_cam->fov = ft_atoi(array[2]);
	num = ft_split(array[0], ',');
	new_cam->orig.x = ft_atof(num[0]);
	new_cam->orig.y = ft_atof(num[1]);
	new_cam->orig.z = ft_atof(num[2]);
	num1 = ft_split(array[1], ',');
	new_cam->dir.x = ft_atof(num1[0]);
	new_cam->dir.y = ft_atof(num1[1]);
	new_cam->dir.z = ft_atof(num1[2]);
	tmp = scena->cams;
	if (!tmp)
		scena->cams = new_cam;
	else
	{
		while (tmp)
		{
			if (tmp->next == NULL)
				break;
			tmp = tmp->next;
		}
		new_cam->prev = tmp;
		tmp->next = new_cam;
	}

	// printf("\n|camera.orig|x: %f|\n", new_cam->orig.x);
	// printf("|camcamera.originera|y: %f|\n", new_cam->orig.y);
	// printf("|camera.orig|z: %f|\n", new_cam->orig.z);

	// printf("\n|camera.dir|x: %f|\n", new_cam->dir.x);
	// printf("|camera.dir|y: %f|\n", new_cam->dir.y);
	// printf("|camera.dir|z: %f|\n", new_cam->dir.z);

	// printf("|fov: %f|", new_cam->fov);
	// printf("\n");
}
