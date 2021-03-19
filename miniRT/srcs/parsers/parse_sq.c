/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:44:46 by qdong             #+#    #+#             */
/*   Updated: 2021/03/17 14:38:22 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		parse_sq(char *line, t_scena scena)
{
	char	**array;
	char	**cordinate;
	char	**cordinate2;

	array = ft_split(line + 1, ' ');

	cordinate = ft_split(array[0], ',');
	scena.sq.center.x = atof(cordinate[0]);
	scena.sq.center.y = atof(cordinate[1]);
	scena.sq.center.z = atof(cordinate[2]);

	cordinate2 = ft_split(array[1], ',');
	scena.sq.normal.x = atof(cordinate2[0]);
	scena.sq.normal.y = atof(cordinate2[1]);
	scena.sq.normal.z = atof(cordinate2[2]);

	scena.sq.side_size = ft_atoi(array[2]);
	scena.sq.color = colors(array[3], scena);
	printf("|sq|scena.sq.center|x|: %f|\n", scena.sq.center.x);
	printf("|scena.sq.center|y|: %f|\n", scena.sq.center.y);
	printf("|scena.sq.center|z|: %f|\n", scena.sq.center.z);
	printf("|scena.sq.normal.x: %f|\n", scena.sq.normal.x);
	printf("|scena.sq.normal.y: %f|\n", scena.sq.normal.y);
	printf("|scena.sq.normal.z: %f|\n", scena.sq.normal.z);
	printf("|side size: %f|\n", scena.sq.side_size);
	printf("|color: %d|\n", scena.sq.color);
}
