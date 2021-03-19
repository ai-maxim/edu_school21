/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:44:30 by qdong             #+#    #+#             */
/*   Updated: 2021/03/17 14:56:34 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		parse_a(char *line, t_scena scena)
{
	char	**array;
	char	**num;

	printf("\nLINE %s\n", array[1]);
	array = ft_split(line + 1, ' ');
	// num = ft_split(array[0], '.');
	scena.brightness = atof(array[0]);
	scena.color = colors(array[1], scena);

	printf("|ambient lightning: %f|", scena.brightness);
	printf("|color: %d|", scena.color);
	printf("\n");
}
