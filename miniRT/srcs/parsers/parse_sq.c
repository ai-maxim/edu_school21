/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:44:46 by qdong             #+#    #+#             */
/*   Updated: 2021/04/19 17:53:28 by qdong            ###   ########.fr       */
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

void	parse_sq_1(t_objs *tmp, t_objs *sq, t_sq *new_sq, t_pars_per p)
{
	new_sq->normal = get_coordinate(p.arr2);
	new_sq->side_size = ft_atoi(p.arr[2]);
	new_sq->len = new_sq->side_size / sqrt(2);
	p.arr3 = ft_split(p.arr[3], ',');
	new_sq->color = get_color(p.arr3);
	sq->data = new_sq;
	sq->type = 'q';
	sq->inter_funk = &sq_intersect;
	sq->next = NULL;
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
	parse_sq_1(tmp, sq, new_sq, p);
	parse_sq_0(tmp, sq, scena);
}
