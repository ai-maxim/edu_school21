/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:26:49 by qdong             #+#    #+#             */
/*   Updated: 2021/03/25 00:23:15 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			parse_tr(char *line, t_scena *scena)
{
	t_pars_per	p;
	t_objs		*tmp;
	t_objs		*tr;
	t_tr		*new_tr;
	t_vec		**color;

	tmp = scena->objs;
	new_tr = malloc(sizeof(t_tr));
	tr = malloc(sizeof(t_objs));
	p.arr = ft_split(line + 1, ' ');
	p.arr1 = ft_split(p.arr[0], ',');
	new_tr->c1 = get_coordinate(p.arr1);
	// new_tr->c1.x = ft_atof(cordinate[0]);
	// new_tr->c1.y = ft_atof(cordinate[1]);
	// new_tr->c1.z = ft_atof(cordinate[2]);
	p.arr2 = ft_split(p.arr[1], ',');
	new_tr->c2 = get_coordinate(p.arr2);

	// new_tr->c2.x = ft_atof(cordinate2[0]);
	// new_tr->c2.y = ft_atof(cordinate2[1]);
	// new_tr->c2.z = ft_atof(cordinate2[2]);
	p.arr3 = ft_split(p.arr[2], ',');
	new_tr->c3 = get_coordinate(p.arr3);
	// new_tr->c3.x = ft_atof(cordinate3[0]);
	// new_tr->c3.y = ft_atof(cordinate3[1]);
	// new_tr->c3.z = ft_atof(cordinate3[2]);
	p.arr4 = ft_split(p.arr[3], ',');
	new_tr->color = get_color(p.arr4);
	// new_tr->color.r = colors(color[0], *scena);
	// new_tr->color.g = colors(color[1], *scena);
	// new_tr->color.b = colors(color[2], *scena);
	tr->data = new_tr;
	tr->type = 't';
	// tr->intersect_funct = &sp_intersect;
	tr->next = NULL;
	if (!tmp)
		scena->objs = tr;
	else
	{
		while (tmp)
		{
			if (tmp->next == NULL)
				break;
			tmp = tmp->next;
		}
		tmp->next = tr;
	}

	// printf("|tr|scena.tr.c: %f|\n", new_tr->c1.x);
	// printf("|tr|scena.tr.c2: %f|\n", new_tr->c1.y);
	// printf("|tr|scena.tr.c2: %f|\n", new_tr->c1.z);

	// printf("|tr|scena.tr.c: %f|\n", new_tr->c1);
	// printf("|tr|scena.tr.c2: %f|\n", new_tr->c2);
	// printf("|tr|scena.tr.c2: %f|\n", new_tr->c3);

	// printf("|tr|scena.tr.c: %f|\n", new_tr->c1);
	// printf("|tr|scena.tr.c2: %f|\n", new_tr->c2);
	// printf("|tr|scena.tr.c2: %f|\n", new_tr->c3);
	// printf("|tr|color: %d|\n", new_tr->color);
	// printf("\n");
}
