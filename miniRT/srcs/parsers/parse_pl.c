/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:36:13 by qdong             #+#    #+#             */
/*   Updated: 2021/04/11 18:24:40 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	get_coordinate(char **str)
{
	t_vec		tmp;

	tmp.x = ft_atof(str[0]);
	tmp.y = ft_atof(str[1]);
	tmp.z = ft_atof(str[2]);
	return (tmp);
}

t_color	get_color(char **str)
{
	t_color		tmp;

	if (!(str[0] && str[1] && str[2]) || str[3])
		ft_exit("Error! No argument is color!\n");
	tmp.r = ft_atoi(str[0]);
	tmp.g = ft_atoi(str[1]);
	tmp.b = ft_atoi(str[2]);
	if ((tmp.r < 0 || tmp.r > 255)
		|| (tmp.g < 0 || tmp.g > 255)
		|| (tmp.b < 0 || tmp.b > 255))
		ft_exit("Error! With colors!\n");
	return (tmp);
}

void	parse_pl_0(t_objs	*tmp, t_objs *pl, t_scena *scena)
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

void	parse_pl(char *line, t_scena *scena)
{
	t_objs		*tmp;
	t_objs		*pl;
	t_pl		*new_pl;
	t_pars_per	p;

	tmp = scena->objs;
	new_pl = malloc(sizeof(t_pl));
	pl = malloc(sizeof(t_objs));
	p.arr = ft_split(line + 1, ' ');
	if (line[0] != ' ')
		ft_exit("Error! With whitespace Plane keys!\n");
	p.arr1 = ft_split(p.arr[0], ',');
	if (!(p.arr1[0] && p.arr1[1] && p.arr1[2]) || p.arr1[3])
		ft_exit("Error! With Plane keys!\n");
	new_pl->center = get_coordinate(p.arr1);
	p.arr2 = ft_split(p.arr[1], ',');
	if (!(p.arr2[0] && p.arr2[1] && p.arr2[2]) || p.arr2[3])
		ft_exit("Error! With Square keys!\n");
	new_pl->normal = get_coordinate(p.arr2);
	p.arr3 = ft_split(p.arr[2], ',');
	new_pl->color = get_color(p.arr3);
	pl->data = new_pl;
	pl->type = 'p';
	pl->inter_funk = &pl_intersect;
	pl->next = NULL;
	parse_pl_0(tmp, pl, scena);
}

	// printf("|plane|center|x: %f\n|", scena.pl.center.x);
	// printf("|plane|center|y: %f\n|", scena.pl.center.y);
	// printf("|plane|center|z: %f\n|", scena.pl.center.z);
	// printf("|normal|x: %f\n|", scena.pl.normal.x);
	// printf("|normal|y: %f\n|", scena.pl.normal.y);
	// printf("|normal|z: %f\n|", scena.pl.normal.z);
	// printf("|color: %d|", scena.pl.color);
	// printf("\n");
