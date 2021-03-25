/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:26:59 by qdong             #+#    #+#             */
/*   Updated: 2021/03/25 00:32:49 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	test_parser(t_scena *scena)
{
	t_objs	*tmp;

	tmp = scena->objs;

	while (tmp)
	{
		if (tmp->type == 't')
		{
			t_tr *tr = tmp->data;
			printf("|tr|scena.tr.c: %f|\n", tr->c1.x);
			printf("|tr|scena.tr.c2: %f|\n", tr->c1.y);
			printf("|tr|scena.tr.c2: %f|\n", tr->c1.z);

			printf("|tr|scena.tr.c: %f|\n", tr->c2.x);
			printf("|tr|scena.tr.c2: %f|\n", tr->c2.y);
			printf("|tr|scena.tr.c2: %f|\n", tr->c2.z);

			printf("|tr|scena.tr.c: %f|\n", tr->c3.x);
			printf("|tr|scena.tr.c2: %f|\n", tr->c3.y);
			printf("|tr|scena.tr.c2: %f|\n", tr->c3.z);
			printf("|tr|color: %d|\n", tr->color.r);
			printf("|tr|color: %d|\n", tr->color.g);
			printf("|tr|color: %d|\n", tr->color.b);
			printf("\n");
		}
		tmp = tmp->next;
	}
}

void			pars_data(char *rt, t_scena *scena)
{
	char		*line;
	int			fd;

	fd = open(rt, O_RDONLY);
	if (fd == -1)
			error_exit(1);
	while ((get_next_line(fd, &line)))
	{
		if (line[0] == 'R')
			parse_r(line + 1, scena);
		if (line[0] == 'A')
			parse_a(line + 1, scena);
		if (line[0] == 'c')
			parse_c(line + 1, scena);
		if (line[0] == 'l')
			parse_l(line + 1, scena);
		if (line[0] == 'p' && line[1] == 'l')
			parse_pl(line + 2, scena);
		if (line[0] == 's' && line[1] == 'p')
			parse_sp(line + 2, scena);
		if (line[0] == 's' && line[1] == 'q')
			parse_sq(line + 2, scena);
		if (line[0] == 'c' && line[1] == 'y')
			parse_cy(line + 2, scena);
		if (line[0] == 't' && line[1] == 'r')
			parse_tr(line + 2, scena);
	}
	test_parser(scena);
}
