/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:34:12 by qdong             #+#    #+#             */
/*   Updated: 2021/03/17 14:58:20 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		parse_l(char *line, t_scena scena)
{
	char	**array;
	char	**cordinate;

	printf("\nLINE %s\n", array[1]);

	array = ft_split(line + 1, ' ');
	scena.light.brightness = atof(array[1]);
	cordinate = ft_split(array[0], ',');
	scena.light.x = ft_atoi(cordinate[0]);
	scena.light.y =	ft_atoi(cordinate[1]);
	scena.light.z = ft_atoi(cordinate[2]);
	scena.light.color = colors(array[2], scena);

	printf("\n|light|x: %f|\n", scena.light.x);
	printf("|light|y: %f|\n", scena.light.y);
	printf("|light|z: %f|\n", scena.light.z);
	printf("|light|brightness: %f|\n", scena.light.brightness);
	printf("|light|color: %d\n|", scena.light.color);
	printf("\n");
}
