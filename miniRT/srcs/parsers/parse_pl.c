/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:36:13 by qdong             #+#    #+#             */
/*   Updated: 2021/03/17 15:00:47 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		parse_pl(char *line, t_scena scena)
{
	char	**array;
	char	**cordinate;
	char	**cordinate2;

	array = ft_split(line + 1, ' ');
	cordinate = ft_split(array[0], ',');
	scena.pl.center.x = ft_atoi(cordinate[0]);
	scena.pl.center.y = ft_atoi(cordinate[1]);
	scena.pl.center.z = ft_atoi(cordinate[2]);
	cordinate2 = ft_split(array[1], ',');
	scena.pl.normal.x = atof(cordinate2[0]);
	scena.pl.normal.y = atof(cordinate2[1]);
	scena.pl.normal.z = atof(cordinate2[2]);
	scena.pl.color = colors(array[2], scena);
	printf("|plane|center|x: %f\n|", scena.pl.center.x);
	printf("|plane|center|y: %f\n|", scena.pl.center.y);
	printf("|plane|center|z: %f\n|", scena.pl.center.z);
	printf("|normal|x: %f\n|", scena.pl.normal.x);
	printf("|normal|y: %f\n|", scena.pl.normal.y);
	printf("|normal|z: %f\n|", scena.pl.normal.z);
	printf("|color: %d|", scena.pl.color);
	printf("\n");
}
