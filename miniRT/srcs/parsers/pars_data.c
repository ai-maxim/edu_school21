/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:26:59 by qdong             #+#    #+#             */
/*   Updated: 2021/04/19 16:14:21 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_line(char *line, t_scena *scena)
{
	if (line[0] == 'R')
		parse_r(line + 1, scena);
	else if (line[0] == 'A')
		parse_a(line + 1, scena);
	else if (line[0] == 'c' && line[1] != 'y')
		parse_c(line + 1, scena);
	else if (line[0] == 'l')
		parse_l(line + 1, scena);
	else if (line[0] == 'p' && line[1] == 'l')
		parse_pl(line + 2, scena);
	else if (line[0] == 's' && line[1] == 'p')
		parse_sp(line + 2, scena);
	else if (line[0] == 's' && line[1] == 'q')
		parse_sq(line + 2, scena);
	else if (line[0] == 'c' && line[1] == 'y')
		parse_cy(line + 2, scena);
	else if (line[0] == 't' && line[1] == 'r')
		parse_tr(line + 2, scena);
	else
		free(line);
}

void	pars_data(char *rt, t_scena *scena)
{
	char	*line;
	int		fd;

	fd = open(rt, O_RDONLY);
	if (fd == -1)
		error_exit(1);
	while ((get_next_line(fd, &line) == 1))
		check_line(line, scena);
	free(line);
}
