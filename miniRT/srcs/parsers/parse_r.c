/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:35:26 by qdong             #+#    #+#             */
/*   Updated: 2021/04/10 17:54:31 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_r(char *line, t_scena *scena)
{
	char	**array;

	array = ft_split(line + 1, ' ');
	if (line[0] != ' ')
		ft_exit("Error! With whitespace Resolution keys!\n");
	if (!(array[0]) || !(array[1]))
		ft_exit("Error! With widht or height!\n");
	scena->widht = ft_atoi(array[0]);
	// if (scena->widht > 5120)
		//TODO
	scena->height = ft_atoi(array[1]);
	// if (scena->height > 2880)
		//TODO
	if (scena->widht <= 0 || scena->height <= 0)
		ft_exit("Error! With widht or height!\n");
}
