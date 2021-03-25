/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:36:13 by qdong             #+#    #+#             */
/*   Updated: 2021/03/24 23:31:57 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec			get_coordinate(char **str)
{
	t_vec		tmp;

	tmp.x = ft_atof(str[0]);
	tmp.y = ft_atof(str[1]);
	tmp.z = ft_atof(str[2]);
	return (tmp);
}

t_color			get_color(char **str)
{
	t_color		tmp;

	tmp.r = ft_atoi(str[0]);
	tmp.g = ft_atoi(str[1]);
	tmp.b = ft_atoi(str[2]);
	return (tmp);
}

void			parse_pl(char *line, t_scena *scena)
{
	t_objs		*tmp;
	t_objs		*pl;
	t_pl		*new_pl;
	t_pars_per	p;

	tmp = scena->objs;
	new_pl = malloc(sizeof(t_pl));
	pl = malloc(sizeof(t_objs));
	p.arr = ft_split(line + 1, ' ');
	p.arr1 = ft_split(p.arr[0], ',');
	new_pl->center = get_coordinate(p.arr1);
	// new_pl->center.x = ft_atoi(cordinate[0]);
	// new_pl->center.y = ft_atoi(cordinate[1]);
	// new_pl->center.z = ft_atoi(cordinate[2]);
	p.arr2 = ft_split(p.arr[1], ',');
	new_pl->normal = get_coordinate(p.arr2);
	// new_pl->normal.x = atof(cordinate2[0]);
	// new_pl->normal.y = atof(cordinate2[1]);
	// new_pl->normal.z = atof(cordinate2[2]);
	p.arr3 = ft_split(p.arr[2], ',');
	new_pl->color = get_color(p.arr3);
	// new_pl->color.r = ft_atoi(color[0]);
	// new_pl->color.g = ft_atoi(color[1]);
	// new_pl->color.b = ft_atoi(color[2]);
	pl->data = new_pl;
	pl->type = 'p';
	// pl->intersect_funct = &pl_intersect;
	pl->next = NULL;
	if (!tmp)
		scena->objs = pl;
	else
	{
		while (tmp)
		{
			if (tmp->next == NULL)
				break;
			tmp = tmp->next;
		}
		tmp->next = pl;
	}

	// printf("|plane|center|x: %f\n|", scena.pl.center.x);
	// printf("|plane|center|y: %f\n|", scena.pl.center.y);
	// printf("|plane|center|z: %f\n|", scena.pl.center.z);
	// printf("|normal|x: %f\n|", scena.pl.normal.x);
	// printf("|normal|y: %f\n|", scena.pl.normal.y);
	// printf("|normal|z: %f\n|", scena.pl.normal.z);
	// printf("|color: %d|", scena.pl.color);
	// printf("\n");
}
