/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:44:46 by qdong             #+#    #+#             */
/*   Updated: 2021/03/25 00:24:09 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			parse_sq(char *line, t_scena *scena)
{
	t_pars_per	p;
	t_objs		*tmp;
	t_objs		*sq;
	t_sq		*new_sq;
	t_vec		**color;

	tmp = scena->objs;
	new_sq = malloc(sizeof(t_sq));
	sq = malloc(sizeof(t_objs));
	p.arr = ft_split(line + 1, ' ');
	p.arr1 = ft_split(p.arr[0], ',');
	new_sq->center = get_coordinate(p.arr1);
	// new_sq->center.x = ft_atof(cordinate[0]);
	// new_sq->center.y = ft_atof(cordinate[1]);
	// new_sq->center.z = ft_atof(cordinate[2]);
	p.arr2 = ft_split(p.arr[1], ',');
	new_sq->normal = get_coordinate(p.arr2);
	// new_sq->normal.x = ft_atof(cordinate2[0]);
	// new_sq->normal.y = ft_atof(cordinate2[1]);
	// new_sq->normal.z = ft_atof(cordinate2[2]);
	new_sq->side_size = ft_atoi(p.arr[2]);
	p.arr3 = ft_split(p.arr[3], ',');
	new_sq->color = get_color(p.arr3);
	// new_sq->color.r = colors(color[0], *scena);
	// new_sq->color.g = colors(color[1], *scena);
	// new_sq->color.b = colors(color[2], *scena);
	sq->data = new_sq;
	sq->type = 'q';
	// sq->intersect_funct = &sq_intersect;
	sq->next = NULL;
	if (!tmp)
		scena->objs = sq;
	else
	{
		while (tmp)
		{
			if (tmp->next == NULL)
				break;
			tmp = tmp->next;
		}
		tmp->next = sq;
	}

	// printf("|sq|new_sq->center|x|: %f|\n", sq->center.x);
	// printf("|new_sq->center|y|: %f|\n", sq->center.y);
	// printf("|new_sq->center|z|: %f|\n", sq->center.z);
	// printf("|new_sq->normal.x: %f|\n", sq->normal.x);
	// 		printf("|new_sq->normal.y: %f|\n", sq->normal.y);
	// 		printf("|new_sq->normal.z: %f|\n", sq->normal.z);
	// 		printf("|side size: %f|\n", sq->side_size);
	// 		printf("|color->r: %d|\n", sq->color.r);
	// 		printf("|color->g: %d|\n", sq->color.g);
	// 		printf("|color->b: %d|\n", sq->color.b);
	// 		printf("\n");
}
