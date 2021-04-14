/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:34:01 by qdong             #+#    #+#             */
/*   Updated: 2021/04/13 14:26:38 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sp_0(t_objs *tmp, t_objs *sp, t_scena *scena)
{
	if (!tmp)
		scena->objs = sp;
	else
	{
		while (tmp)
		{
			if (tmp->next == NULL)
				break ;
			tmp = tmp->next;
		}
		tmp->next = sp;
	}
}

void	parse_sp(char *line, t_scena *scena)
{
	t_pars_per	p;
	t_objs		*tmp;
	t_objs		*sp;
	t_sp		*new_sp;

	tmp = scena->objs;
	new_sp = malloc(sizeof(t_sp));
	sp = malloc(sizeof(t_objs));
	p.arr = ft_split(line + 1, ' ');
	if (line[0] != ' ')
		ft_exit("Error! With whitespace Shpera keys!\n");
	if (!(p.arr[0] && p.arr[1] && p.arr[2]) || p.arr[3])
		ft_exit("Error! With Shpera argument!\n");
	p.arr1 = ft_split(p.arr[0], ',');
	if (!(p.arr1[0] && p.arr1[1] && p.arr1[2]) || p.arr1[3])
		ft_exit("Error! With Shpera argument center!\n");
	new_sp->center = get_coordinate(p.arr1);
	// if (!p.arr1)
	// 	ft_exit("Error! With Shpera argument diam!\n");
	new_sp->diam = ft_atof(p.arr[1]);
	p.arr2 = ft_split(p.arr[2], ',');
	new_sp->color = get_color(p.arr2);
	sp->data = new_sp;
	sp->type = 's';
	sp->inter_funk = &sp_intersect;
	sp->next = NULL;
	parse_sp_0(tmp, sp, scena);

	// printf("|sphera|center|x: %f\n|", new_sp->center.x);
	// printf("|sphera|center|y: %f\n|", new_sp->center.y);
	// printf("|sphera|center|z: %f\n|", new_sp->center.z);
	// printf("|radius: %f\n|", new_sp->diam);
	// printf("|color: %d|", new_sp->color.r);
	// printf("|color: %d|", new_sp->color.g);
	// printf("|color: %d|", new_sp->color.b);
	// printf("\n");
}
