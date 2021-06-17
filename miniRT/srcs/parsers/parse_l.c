/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:34:12 by qdong             #+#    #+#             */
/*   Updated: 2021/04/22 20:02:08 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_l0(t_light *tmp, t_light *new_light, t_scena *scena)
{
	tmp = scena->light;
	if (!tmp)
		scena->light = new_light;
	else
	{
		while (tmp)
		{
			if (tmp->next == NULL)
				break ;
			tmp = tmp->next;
		}
		tmp->next = new_light;
	}
}

void	parse_l_color(t_light *new_light, char **array)
{
	char	**cordinate1;

	cordinate1 = ft_split(array[2], ',');
	if (!(cordinate1[0] && cordinate1[1] && cordinate1[2]) || cordinate1[3])
		ft_exit("Error! With colors!\n");
	new_light->color.r = ft_atoi(cordinate1[0]);
	new_light->color.g = ft_atoi(cordinate1[1]);
	new_light->color.b = ft_atoi(cordinate1[2]);
	if ((new_light->color.r < 0 || new_light->color.r > 255)
		|| (new_light->color.g < 0 || new_light->color.g > 255)
		|| (new_light->color.b < 0 || new_light->color.b > 255))
		ft_exit("Error! With colors!\n");
	free_array(cordinate1);
}

void	parse_l1(char *line, t_light *new_light)
{
	char	**array;
	char	**cordinate;

	array = ft_split(line + 1, ' ');
	if (line[0] != ' ')
		ft_exit("Error! With whitespace Light keys!\n");
	if (!(array[0] && array[1] && array[2]) || array[3])
		ft_exit("Error! With l keys!\n");
	cordinate = ft_split(array[0], ',');
	if (!(cordinate[0] && cordinate[1] && cordinate[2]) || cordinate[3])
		ft_exit("Error! With l_dot!\n");
	new_light->l_dot.x = ft_atof(cordinate[0]);
	new_light->l_dot.y = ft_atof(cordinate[1]);
	new_light->l_dot.z = ft_atof(cordinate[2]);
	new_light->brightness = ft_atof(array[1]);
	if (new_light->brightness <= 0 || new_light->brightness > 1)
		ft_exit("Error! With L-brightness!\n");
	parse_l_color(new_light, array);
	free_array(array);
	free_array(cordinate);
}

void	parse_l(char *line, t_scena *scena)
{
	t_light		*tmp;
	t_light		*new_light;

	tmp = NULL;
	new_light = (t_light *)malloc(sizeof(t_light));
	if (!new_light)
		ft_exit("ERROR: malloc");
	new_light->next = NULL;
	parse_l0(tmp, new_light, scena);
	parse_l1(line, new_light);
}
