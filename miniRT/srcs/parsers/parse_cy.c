/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:14:21 by qdong             #+#    #+#             */
/*   Updated: 2021/03/17 15:03:36 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		parse_cy(char *line, t_scena scena)
{
	char	**array;
	char	**cordinate;
	char	**cordinate2;

	printf("%s", line);
	array = ft_split(line + 1, ' ');
	cordinate = ft_split(array[0], ',');
	scena.cy.center.x = atof(cordinate[0]);
	scena.cy.center.y = atof(cordinate[1]);
	scena.cy.center.z = atof(cordinate[2]);
	cordinate2 = ft_split(array[1], ',');
	scena.cy.direction.x = atof(cordinate2[0]);
	scena.cy.direction.x = atof(cordinate2[1]);
	scena.cy.direction.z = atof(cordinate2[2]);
	scena.cy.radius = atof(array[2]);
	scena.cy.height = atof(array[3]);
	scena.cy.color = colors(array[4], scena);
	printf("|scena.cy.center|x|: %f|\n", scena.cy.center.x);
	printf("|scena.cy.center|y|: %f|\n", scena.cy.center.y);
	printf("|scena.cy.center|z|: %f|\n", scena.cy.center.z);
	printf("|scena.cy.direction.x: %f|\n", scena.cy.direction.x);
	printf("|scena.cy.direction.y: %f|\n", scena.cy.direction.y);
	printf("|scena.cy.direction.z: %f|\n", scena.cy.direction.z);
	printf("|scena.cy.radius: %f|\n", scena.cy.radius);
	printf("|scena.cy.height: %f|\n", scena.cy.height);
	printf("|color: %d|\n", scena.cy.color);
}
