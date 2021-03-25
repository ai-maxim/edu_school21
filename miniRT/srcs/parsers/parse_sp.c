/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:34:01 by qdong             #+#    #+#             */
/*   Updated: 2021/03/24 23:47:49 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			parse_sp(char *line, t_scena *scena)
{
	t_pars_per	p;
	t_objs		*tmp;
	t_objs		*sp;
	t_sp		*new_sp;

	tmp = scena->objs;
	new_sp = malloc(sizeof(t_sp));
	sp = malloc(sizeof(t_objs));
	p.arr = ft_split(line + 1, ' ');
	p.arr1 = ft_split(p.arr[0], ',');
	new_sp->center = get_coordinate(p.arr1);
	// new_sp->center.x = ft_atof(p.arr1[0]);
	// new_sp->center.y = ft_atof(p.arr1[1]);
	// new_sp->center.z = ft_atof(p.arr1[2]);
	new_sp->diam = ft_atof(p.arr[1]);
	p.arr2 = ft_split(p.arr[2], ',');
	new_sp->color = get_color(p.arr2);
	// new_sp->color.r = colors(color[0], *scena);
	// new_sp->color.g = colors(color[1], *scena);
	// new_sp->color.b = colors(color[2], *scena);
	sp->data = new_sp;
	sp->type = 's';
	// sp->intersect_funct = &sp_intersect;
	sp->next = NULL;
	if (!tmp)
		scena->objs = sp;
	else
	{
		while (tmp)
		{
			if (tmp->next == NULL)
				break;
			tmp = tmp->next;
		}
		tmp->next = sp;
	}

	// printf("|sphera|center|x: %f\n|", new_sp->center.x);
	// printf("|sphera|center|y: %f\n|", new_sp->center.y);
	// printf("|sphera|center|z: %f\n|", new_sp->center.z);
	// printf("|radius: %f\n|", new_sp->diam);
	// printf("|color: %d|", new_sp->color.r);
	// printf("|color: %d|", new_sp->color.g);
	// printf("|color: %d|", new_sp->color.b);
	// printf("\n");
}
