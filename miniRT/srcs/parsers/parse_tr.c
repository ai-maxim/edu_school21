/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:26:49 by qdong             #+#    #+#             */
/*   Updated: 2021/04/22 20:18:01 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_tr_0(t_objs	*tmp, t_objs *tr, t_scena *scena)
{
	if (!tmp)
		scena->objs = tr;
	else
	{
		while (tmp)
		{
			if (tmp->next == NULL)
				break ;
			tmp = tmp->next;
		}
		tmp->next = tr;
	}
}

void	parse_tr1(t_objs *tr, t_tr *new_tr, t_pars_per p)
{
	new_tr->color = get_color(p.arr4);
	tr->data = new_tr;
	tr->type = 't';
	tr->inter_funk = &tr_intersect;
	tr->next = NULL;
}

void	parse_if(t_pars_per *p, t_tr *new_tr)
{
	if (!(p->arr[0] && p->arr[1] && p->arr[2] && p->arr[3]) || p->arr[4])
		ft_exit("Error! No argument is tr!\n");
	p->arr1 = ft_split(p->arr[0], ',');
	if (!(p->arr1[0] && p->arr1[1] && p->arr1[2]) || p->arr1[3])
		ft_exit("Error! No argument is c1 tr!\n");
	new_tr->c1 = get_coordinate(p->arr1);
	p->arr2 = ft_split(p->arr[1], ',');
	if (!(p->arr2[0] && p->arr2[1] && p->arr2[2]) || p->arr2[3])
		ft_exit("Error! No argument is c2 tr!\n");
	new_tr->c2 = get_coordinate(p->arr2);
	p->arr3 = ft_split(p->arr[2], ',');
	if (!(p->arr3[0] && p->arr3[1] && p->arr3[2]) || p->arr3[3])
		ft_exit("Error! No argument is c3 tr!\n");
	new_tr->c3 = get_coordinate(p->arr3);
	p->arr4 = ft_split(p->arr[3], ',');
	if (!(p->arr4[0] && p->arr4[1] && p->arr4[2]) || p->arr4[3])
		ft_exit("Error! No argument is color!\n");
}

void	parse_tr(char *line, t_scena *scena)
{
	t_pars_per	p;
	t_objs		*tmp;
	t_objs		*tr;
	t_tr		*new_tr;

	tmp = scena->objs;
	new_tr = malloc(sizeof(t_tr));
	if (!new_tr)
		ft_exit("ERROR: malloc");
	tr = malloc(sizeof(t_objs));
	if (!tr)
		ft_exit("ERROR: malloc");
	p.arr = ft_split(line + 1, ' ');
	if (line[0] != ' ')
		ft_exit("Error! With whitespace Triangle keys!\n");
	parse_if(&p, new_tr);
	parse_tr1(tr, new_tr, p);
	parse_tr_0(tmp, tr, scena);
	free_array(p.arr);
	free_array(p.arr1);
	free_array(p.arr2);
	free_array(p.arr3);
	free_array(p.arr4);
}
