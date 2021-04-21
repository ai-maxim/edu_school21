/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:14:21 by qdong             #+#    #+#             */
/*   Updated: 2021/04/20 21:05:01 by qdong            ###   ########.fr       */
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

void	parse_cy1(t_objs *tmp, t_objs *cy, t_cy *new_cy, t_pars_per	p)
{
	new_cy->color = get_color(p.arr3);
	cy->data = new_cy;
	cy->type = 'c';
	cy->inter_funk = &cy_intersect;
	cy->next = NULL;
}

void	parse_cy(char *line, t_scena *scena)
{
	t_pars_per	p;
	t_objs		*tmp;
	t_objs		*cy;
	t_cy		*new_cy;

	tmp = scena->objs;
	new_cy = malloc(sizeof(t_cy));
	cy = malloc(sizeof(t_objs));
	p.arr = ft_split(line + 1, ' ');
	if (line[0] != ' ')
		ft_exit("Error! With whitespace Cylinder keys!\n");
	p.arr1 = ft_split(p.arr[0], ',');
	if (!(p.arr1[0] && p.arr1[1] && p.arr1[2]) || p.arr1[3])
		ft_exit("Error! With Cylinder[center] keys!\n");
	new_cy->center = get_coordinate(p.arr1);
	p.arr2 = ft_split(p.arr[1], ',');
	if (!(p.arr2[0] && p.arr2[1] && p.arr2[2]) || p.arr2[3])
		ft_exit("Error! With Cylinder[dir] keys!\n");
	new_cy->dir = get_coordinate(p.arr2);
	new_cy->diam = ft_atof(p.arr[2]);
	new_cy->height = ft_atof(p.arr[3]);
	p.arr3 = ft_split(p.arr[4], ',');
	parse_cy1(tmp, cy, new_cy, p);
	parse_cy_0(tmp, cy, scena);
}
