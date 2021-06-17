/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:34:01 by qdong             #+#    #+#             */
/*   Updated: 2021/04/22 20:16:20 by qdong            ###   ########.fr       */
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

void	parse_sp1(t_objs *sp, t_sp *new_sp, t_pars_per	p)
{
	new_sp->color = get_color(p.arr2);
	sp->data = (void *)new_sp;
	sp->type = 's';
	sp->inter_funk = &sp_intersect;
	sp->next = NULL;
}

void	parse_if_sp(t_pars_per *p, char *line)
{
	p->arr = ft_split(line + 1, ' ');
	if (!(p->arr[0] && p->arr[1] && p->arr[2]) || (p->arr[3]))
		ft_exit("Error! With Cylinder keys!\n");
	if (line[0] != ' ')
		ft_exit("Error! With whitespace Shpera keys!\n");
	if (!(p->arr[0] && p->arr[1] && p->arr[2]) || p->arr[3])
		ft_exit("Error! With Shpera argument!\n");
	p->arr1 = ft_split(p->arr[0], ',');
	if (!(p->arr1[0] && p->arr1[1] && p->arr1[2]) || p->arr1[3])
		ft_exit("Error! With Shpera argument center!\n");
}

void	parse_sp(char *line, t_scena *scena)
{
	t_pars_per	p;
	t_objs		*tmp;
	t_objs		*sp;
	t_sp		*new_sp;

	tmp = scena->objs;
	new_sp = malloc(sizeof(t_sp));
	if (!new_sp)
		ft_exit("ERROR: malloc");
	sp = malloc(sizeof(t_objs));
	if (!sp)
		ft_exit("ERROR: malloc");
	parse_if_sp(&p, line);
	new_sp->center = get_coordinate(p.arr1);
	new_sp->diam = ft_atof(p.arr[1]);
	if (new_sp->diam < 0)
		ft_exit("Error! With Shpera argument diam!\n");
	p.arr2 = ft_split(p.arr[2], ',');
	parse_sp1(sp, new_sp, p);
	parse_sp_0(tmp, sp, scena);
	free_array(p.arr);
	free_array(p.arr1);
	free_array(p.arr2);
}
