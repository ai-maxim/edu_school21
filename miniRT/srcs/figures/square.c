/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:27 by qdong             #+#    #+#             */
/*   Updated: 2021/03/19 20:27:33 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_general 		*new_square(t_vec center, t_vec normal, float side_size)
{
	t_general	*square;

	square = malloc(sizeof(t_general));
	if (!square)
		error_exit(-1);
	square->center = center;
	square->normal = normal;
	square->side_size = side_size;
//	square->color = color;
	square->type = 'q';
	return (square);
}
