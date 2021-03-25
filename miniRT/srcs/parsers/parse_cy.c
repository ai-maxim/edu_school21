/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:14:21 by qdong             #+#    #+#             */
/*   Updated: 2021/03/25 00:29:53 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			parse_cy(char *line, t_scena *scena)
{
	t_pars_per	p;
	t_objs		*tmp;
	t_objs		*cy;
	t_cy		*new_cy;
	t_vec		**color;

	tmp = scena->objs;
	new_cy = malloc(sizeof(t_cy));
	cy = malloc(sizeof(t_objs));
	p.arr = ft_split(line + 1, ' ');
	p.arr1 = ft_split(p.arr[0], ',');
	new_cy->center = get_coordinate(p.arr1);
	// new_cy->center.x = ft_atof(cordinate[0]);
	// new_cy->center.y = ft_atof(cordinate[1]);
	// new_cy->center.z = ft_atof(cordinate[2]);
	p.arr2 = ft_split(p.arr[1], ',');
	new_cy->dir = get_coordinate(p.arr2);
	// new_cy->dir.x = ft_atof(cordinate2[0]);
	// new_cy->dir.y = ft_atof(cordinate2[1]);
	// new_cy->dir.z = ft_atof(cordinate2[2]);
	new_cy->diam = ft_atof(p.arr[2]);
	new_cy->height = ft_atof(p.arr[3]);
	p.arr3 = ft_split(p.arr[4], ',');
	new_cy->color = get_color(p.arr3);
	// new_cy->color.r = ft_atoi(color[0]);
	// new_cy->color.g = ft_atoi(color[1]);
	// new_cy->color.b = ft_atoi(color[2]);
	cy->data = new_cy;
	cy->type = 'c';
	// cy->intersect_funct = &cy_intersect;
	cy->next = NULL;
	if (!tmp)
		scena->objs = cy;
	else
	{
		while (tmp)
		{
			if (tmp->next == NULL)
				break;
			tmp = tmp->next;
		}
		tmp->next = cy;
	}

	// printf("|new_cy->center: %f|\n", new_cy->center.x);
	// printf("|new_cy->center %f|\n", new_cy->center.y);
	// printf("|new_cy->center: %f|\n", new_cy->center.z);
	// printf("|new_cy->dir.x: %f|\n", new_cy->dir.x);
	// printf("|new_cy->dir.y: %f|\n", new_cy->dir.y);
	// printf("|new_cy->dir.z: %f|\n", new_cy->dir.z);
	// printf("|new_cy->diam: %f|\n", new_cy->diam);
	// printf("|new_cy->dirf|\n", new_cy->height);
	// printf("|color->r: %d|\n", new_cy->color.r);
	// printf("|color->g: %d|\n", new_cy->color.g);
	// printf("|color->b: %d|\n", new_cy->color.b);
}
