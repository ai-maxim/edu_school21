/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:34:01 by qdong             #+#    #+#             */
/*   Updated: 2021/03/17 15:02:13 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		parse_sp(char *line, t_scena scena)
{
	char	**array;
	char	**cordinate;

	array = ft_split(line + 1, ' ');
	cordinate = ft_split(array[0], ',');
	scena.sp.center.x = ft_atoi(cordinate[0]);
	scena.sp.center.y = ft_atoi(cordinate[1]);
	scena.sp.center.z = ft_atoi(cordinate[2]);
	scena.sp.radius = ft_atoi(array[1]);
	scena.sp.color = colors(array[2], scena);
	printf("|sphera|center|x: %f\n|", scena.sp.center.x);
	printf("|sphera|center|y: %f\n|", scena.sp.center.y);
	printf("|sphera|center|z: %f\n|", scena.sp.center.z);
	printf("|radius: %f\n|", scena.sp.radius);
	printf("|color: %d|", scena.sp.color);
	printf("\n");
}
