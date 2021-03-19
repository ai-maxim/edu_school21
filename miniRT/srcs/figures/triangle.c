/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:47:07 by qdong             #+#    #+#             */
/*   Updated: 2021/03/17 14:30:42 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_general	*new_triangle(t_vec c, t_vec c1, t_vec c2, int color)
{
	t_general	*triangle;

	triangle = malloc(sizeof(t_general));
	if (!triangle)
		error_exit(-1);
	triangle->c = c;
	triangle->c1 = c1;
	triangle->c2 = c2;
	triangle->color = color;
	triangle->type = 't';
	return (triangle);
}
