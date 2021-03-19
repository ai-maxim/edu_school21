/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:26:49 by qdong             #+#    #+#             */
/*   Updated: 2021/03/17 15:16:47 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		parse_tr(char *line, t_scena scena)
{
	char	**array;
	char	**cordinate;
	char	**cordinate2;
	char	**cordinate3;

	array = ft_split(line + 1, ' ');
	cordinate = ft_split(array[0], ',');
	scena.tr.x_c = atof(cordinate[0]);
	scena.tr.y_c = atof(cordinate[1]);
	scena.tr.z_c = atof(cordinate[2]);
	cordinate2 = ft_split(array[1], ',');
	scena.tr.x_c2 = atof(cordinate2[0]);
	scena.tr.y_c2 = atof(cordinate2[1]);
	scena.tr.z_c2 = atof(cordinate2[2]);
	cordinate3 = ft_split(array[2], ',');
	scena.tr.x_c3 = atof(cordinate3[0]);
	scena.tr.y_c3 = atof(cordinate3[1]);
	scena.tr.z_c3 = atof(cordinate3[2]);
	scena.tr.color = colors(array[3], scena);

	printf("|tr|scena.tr.c: %f|\n", scena.tr.x_c);
	printf("|tr|scena.tr.c2: %f|\n", scena.tr.y_c);
	printf("|tr|scena.tr.c2: %f|\n", scena.tr.z_c);
	printf("|tr|scena.tr.c: %f|\n", scena.tr.x_c2);
	printf("|tr|scena.tr.c2: %f|\n", scena.tr.y_c2);
	printf("|tr|scena.tr.c2: %f|\n", scena.tr.z_c2);
	printf("|tr|scena.tr.c: %f|\n", scena.tr.x_c3);
	printf("|tr|scena.tr.c2: %f|\n", scena.tr.y_c3);
	printf("|tr|scena.tr.c2: %f|\n", scena.tr.z_c3);
	printf("|tr|color: %d|\n", scena.tr.color);
	printf("\n");
}
