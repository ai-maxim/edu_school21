/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:44:30 by qdong             #+#    #+#             */
/*   Updated: 2021/04/09 13:38:11 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_a(char *line, t_scena *scena)
{
	char	**array;
	char	**tmp;

	array = ft_split(line + 1, ' ');
	if (line[0] != ' ')
		ft_exit("Error! With whitespace Ambient Lightning keys!\n");
	if (!(array[0]) || !(array[1]))
		ft_exit("Error! With parse A!\n");
	scena->brightness = ft_atof(array[0]);
	if (scena->brightness <= 0 || scena->brightness > 1)
		ft_exit("Error! With brightness!\n");
	tmp = array;
	array = ft_split(array[1], ',');
	if (!(array[0] && array[1] && array[2]) || array[3])
		ft_exit("Error! With colors!\n");
	scena->color.r = ft_atoi(array[0]);
	scena->color.g = ft_atoi(array[1]);
	scena->color.b = ft_atoi(array[2]);
	if ((scena->color.r < 0 || scena->color.r > 255)
		|| (scena->color.g < 0 || scena->color.g > 255)
		|| (scena->color.b < 0 || scena->color.b > 255))
		error_color(&array[1]);
	free(tmp);
	free(array);

	// printf("|ambient lightning: %f|\n", scena->brightness);
	// printf("|color r: %d|\n", scena->color.r);
	// printf("|color g: %d|\n", scena->color.g);
	// printf("|color b: %d|\n", scena->color.b);
	// printf("\n");
}
