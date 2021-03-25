/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:34:12 by qdong             #+#    #+#             */
/*   Updated: 2021/03/24 23:43:09 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		parse_l(char *line, t_scena *scena)
{
	char	**array;
	char	**cordinate;
	char	**cordinate1;
	t_light	*tmp;
	t_light	*new_light;

	new_light = malloc(sizeof(t_light));
	new_light->next = NULL;
	array = ft_split(line + 1, ' ');
	cordinate = ft_split(array[0], ',');
	new_light->l_dot.x = ft_atof(cordinate[0]);
	new_light->l_dot.y = ft_atof(cordinate[1]);
	new_light->l_dot.z = ft_atof(cordinate[2]);
	new_light->brightness = ft_atof(array[1]);
	cordinate1 = ft_split(array[2], ',');
	new_light->color.r = ft_atoi(cordinate1[0]);
	new_light->color.g = ft_atoi(cordinate1[1]);
	new_light->color.b = ft_atoi(cordinate1[2]);
	tmp = scena->light;
	if (!tmp)
		scena->light = new_light;
	else
	{
		while (tmp)
		{
			if (tmp->next == NULL)
				break;
			tmp = tmp->next;
		}
		tmp->next = new_light;
	}
	// printf("\n|light|x: %f|\n", new_light->l_dot.x);
	// printf("|light|y: %f|\n", new_light->l_dot.y);
	// printf("|light|z: %f|\n", new_light->l_dot.z);
	// printf("|light|brightness: %f|\n", new_light->brightness);
	// printf("|light|color: %d\n|", new_light->color.r);
	// printf("|light|color: %d\n|", new_light->color.g);
	// printf("|light|color: %d\n|", new_light->color.b);
	// printf("\n");
}
