/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:14:21 by qdong             #+#    #+#             */
/*   Updated: 2021/04/22 20:01:27 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_cy_0(t_objs *tmp, t_objs *cy, t_scena *scena)
{
	if (!tmp)
		scena->objs = cy;
	else
	{
		while (tmp)
		{
			if (tmp->next == NULL)
				break ;
			tmp = tmp->next;
		}
		tmp->next = cy;
	}
}

void	parse_cy1(t_objs *cy, t_cy *new_cy, char **color_cy)
{
	new_cy->color = get_color(color_cy);
	cy->data = new_cy;
	cy->type = 'c';
	cy->inter_funk = &cy_intersect;
	cy->next = NULL;
}

void	parse_cy2(t_cy *new_cy, t_pars_per p)
{
	new_cy->dir = get_coordinate(p.arr2);
	new_cy->diam = ft_atof(p.arr[2]);
	new_cy->height = ft_atof(p.arr[3]);
}

void	parse_if_cy(t_pars_per *p, t_cy *new_cy)
{
	if (!(p->arr[0] && p->arr[1] && p->arr[2] && p->arr[3] && p->arr[4])
		|| (p->arr[5]))
		ft_exit("Error! With Cylinder keys!\n");
	p->arr1 = ft_split(p->arr[0], ',');
	if (!(p->arr1[0] && p->arr1[1] && p->arr1[2]) || p->arr1[3])
		ft_exit("Error! With Cylinder[center] keys!\n");
	new_cy->center = get_coordinate(p->arr1);
	p->arr2 = ft_split(p->arr[1], ',');
	if (!(p->arr2[0] && p->arr2[1] && p->arr2[2]) || p->arr2[3])
		ft_exit("Error! With Cylinder[dir] keys!\n");
}

void	parse_cy(char *line, t_scena *scena)
{
	t_pars_per	p;
	t_objs		*tmp;
	t_objs		*cy;
	t_cy		*new_cy;

	tmp = scena->objs;
	new_cy = malloc(sizeof(t_cy));
	if (!new_cy)
		ft_exit("ERROR: malloc");
	cy = malloc(sizeof(t_objs));
	if (!cy)
		ft_exit("ERROR: malloc");
	p.arr = ft_split(line + 1, ' ');
	if (line[0] != ' ')
		ft_exit("Error! With whitespace Cylinder keys!\n");
	parse_if_cy(&p, new_cy);
	check_normalaz(p.arr2[0], p.arr2[1], p.arr2[2]);
	parse_cy2(new_cy, p);
	p.arr3 = ft_split(p.arr[4], ',');
	parse_cy1(cy, new_cy, p.arr3);
	parse_cy_0(tmp, cy, scena);
	free_array(p.arr);
	free_array(p.arr1);
	free_array(p.arr2);
	free_array(p.arr3);
}
