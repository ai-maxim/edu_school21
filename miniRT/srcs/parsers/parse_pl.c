/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:36:13 by qdong             #+#    #+#             */
/*   Updated: 2021/04/22 20:11:10 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_pl_0(t_objs *tmp, t_objs *pl, t_scena *scena)
{
	if (!tmp)
		scena->objs = pl;
	else
	{
		while (tmp)
		{
			if (tmp->next == NULL)
				break ;
			tmp = tmp->next;
		}
		tmp->next = pl;
	}
}

void	parse_pl1(t_objs *pl, t_pl *new_pl, t_pars_per p)
{
	new_pl->normal = get_coordinate(p.arr2);
	p.arr3 = ft_split(p.arr[2], ',');
	new_pl->color = get_color(p.arr3);
	pl->data = new_pl;
	pl->type = 'p';
	pl->inter_funk = &pl_intersect;
	pl->next = NULL;
	free_array(p.arr3);
}

void	parse_if_pl(t_pars_per *p, t_pl *new_pl, char *line)
{
	p->arr = ft_split(line + 1, ' ');
	if (line[0] != ' ')
		ft_exit("Error! With whitespace Plane keys!\n");
	p->arr1 = ft_split(p->arr[0], ',');
	if (!(p->arr1[0] && p->arr1[1] && p->arr1[2]) || p->arr1[3])
		ft_exit("Error! With Plane keys!\n");
	new_pl->center = get_coordinate(p->arr1);
	p->arr2 = ft_split(p->arr[1], ',');
	if (!(p->arr2[0] && p->arr2[1] && p->arr2[2]) || p->arr2[3])
		ft_exit("Error! With Square keys!\n");
}

void	parse_pl(char *line, t_scena *scena)
{
	t_objs		*tmp;
	t_objs		*pl;
	t_pl		*new_pl;
	t_pars_per	p;

	tmp = scena->objs;
	new_pl = malloc(sizeof(t_pl));
	if (!new_pl)
		ft_exit("ERROR: malloc");
	pl = malloc(sizeof(t_objs));
	if (!pl)
		ft_exit("ERROR: malloc");
	parse_if_pl(&p, new_pl, line);
	check_normalaz(p.arr2[0], p.arr2[1], p.arr2[2]);
	parse_pl1(pl, new_pl, p);
	parse_pl_0(tmp, pl, scena);
	free_array(p.arr);
	free_array(p.arr1);
	free_array(p.arr2);
}
