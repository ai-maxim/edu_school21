/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:44:46 by qdong             #+#    #+#             */
/*   Updated: 2021/04/11 18:25:59 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sq_0(t_objs	*tmp, t_objs *sq, t_scena *scena)
{
	if (!tmp)
		scena->objs = sq;
	else
	{
		while (tmp)
		{
			if (tmp->next == NULL)
				break ;
			tmp = tmp->next;
		}
		tmp->next = sq;
	}
}

void	parse_sq(char *line, t_scena *scena)
{
	t_pars_per	p;
	t_objs		*tmp;
	t_objs		*sq;
	t_sq		*new_sq;

	tmp = scena->objs;
	new_sq = malloc(sizeof(t_sq));
	sq = malloc(sizeof(t_objs));
	p.arr = ft_split(line + 1, ' ');
	if (line[0] != ' ')
		ft_exit("Error! With whitespace Square keys!\n");
	if (!(p.arr[0] && p.arr[1] && p.arr[2] && p.arr[3]) || p.arr[4])
		ft_exit("Error! No argument is sq!\n");
	p.arr1 = ft_split(p.arr[0], ',');
	if (!(p.arr1[0] && p.arr1[1] && p.arr1[2]) || p.arr1[3])
		ft_exit("Error! No argument is sq[center]!\n");
	new_sq->center = get_coordinate(p.arr1);
	p.arr2 = ft_split(p.arr[1], ',');
	if (!(p.arr2[0] && p.arr2[1] && p.arr2[2]) || p.arr2[3])
		ft_exit("Error! With Square[normal] keys!\n");
	new_sq->normal = get_coordinate(p.arr2);
	new_sq->side_size = ft_atoi(p.arr[2]);
	p.arr3 = ft_split(p.arr[3], ',');
	new_sq->color = get_color(p.arr3);
	sq->data = new_sq;
	sq->type = 'q';
	// sq->inter_funk = &sq_intersect;
	sq->next = NULL;
	parse_sq_0(tmp, sq, scena);
}

	// printf("|sq|new_sq->center|x|: %f|\n", sq->center.x);
	// printf("|new_sq->center|y|: %f|\n", sq->center.y);
	// printf("|new_sq->center|z|: %f|\n", sq->center.z);
	// printf("|new_sq->normal.x: %f|\n", sq->normal.x);
	// printf("|new_sq->normal.y: %f|\n", sq->normal.y);
	// printf("|new_sq->normal.z: %f|\n", sq->normal.z);
	// printf("|side size: %f|\n", sq->side_size);
	// printf("|color->r: %d|\n", sq->color.r);
	// printf("|color->g: %d|\n", sq->color.g);
	// printf("|color->b: %d|\n", sq->color.b);
	//printf("\n");
