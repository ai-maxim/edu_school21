/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:26:54 by qdong             #+#    #+#             */
/*   Updated: 2021/03/16 19:45:13 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		parse_c(char *line, t_scena scena)
{
	char	**array;
	char	**num;
	char	**num1;

	array = ft_split(line + 1, ' ');
	// scena.origin = atof(array[0]);
	// scena.direction = ft_atoi(array[1]);
	scena.fov = ft_atoi(array[2]);

	num = ft_split(array[0], ',');
	scena.camera.origin.x = atof(num[0]);
	scena.camera.origin.y = atof(num[1]);
	scena.camera.origin.z = ft_atoi(num[2]);

	num1 = ft_split(array[1], ',');
	scena.camera.direction.x = ft_atoi(num1[0]);
	scena.camera.direction.y = ft_atoi(num1[1]);
	scena.camera.direction.z = ft_atoi(num1[2]);

	printf("\n|camera.origin|x: %f|\n", scena.camera.origin.x);
	printf("|camcamera.originera|y: %f|\n", scena.camera.origin.y);
	printf("|camera.origin|z: %f|\n", scena.camera.origin.z);

	printf("\n|camera.direction|x: %f|\n", scena.camera.direction.x);
	printf("|camera.direction|y: %f|\n", scena.camera.direction.y);
	printf("|camera.direction|z: %f|\n", scena.camera.direction.z);
	// printf("|camera|origin: %f|", scena.origin);
	// printf("|direction: %d|", scena.direction);
	printf("|fov: %f|", scena.fov);
	printf("\n");
}
