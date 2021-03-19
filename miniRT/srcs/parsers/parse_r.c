/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:35:26 by qdong             #+#    #+#             */
/*   Updated: 2021/03/16 17:35:18 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			parse_r(char *line, t_scena scena)
{
	char		**array;

	array = ft_split(line + 1, ' ');
	scena.widht = ft_atoi(array[0]);
	scena.height = ft_atoi(array[1]);
	printf("|R|w: %d|", scena.widht);
	printf("|h: %d|", scena.height);
	printf("\n");
}
