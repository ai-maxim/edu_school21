/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:44:30 by qdong             #+#    #+#             */
/*   Updated: 2021/03/24 23:43:22 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		parse_a(char *line, t_scena *scena)
{
	char	**array;
	char	**tmp;
	array = ft_split(line + 1, ' ');
	scena->brightness = ft_atof(array[0]);
	tmp = array;
	array = ft_split(array[1], ',');
	scena->color.r = ft_atoi(array[0]);
	scena->color.g = ft_atoi(array[1]);
	scena->color.b = ft_atoi(array[2]);
	free(tmp);
	free(array);

	// printf("|ambient lightning: %f|", scena->brightness);
	// printf("|color r: %d|",scena->color.r);
	// printf("|color g: %d|",scena->color.g);
	// printf("|color b: %d|",scena->color.b);
	// printf("\n");
}
