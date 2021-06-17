/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 19:01:48 by qdong             #+#    #+#             */
/*   Updated: 2021/04/22 16:04:57 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	color_scalar_ret(double n, t_color *c)
{
	t_color	result;

	result.r = c->r * n;
	result.g = c->g * n;
	result.b = c->b * n;
	return (result);
}

t_color	mix_col(t_color *c1, t_color *c2)
{
	t_color	result;

	result.r = c1->r * (c2->r / 255.);
	result.g = c1->g * (c2->g / 255.);
	result.b = c1->b * (c2->b / 255.);
	return (result);
}

t_color	col_sum(t_color *c1, t_color *c2)
{
	t_color	result;

	result.r = c1->r + c2->r;
	result.g = c1->g + c2->g;
	result.b = c1->b + c2->b;
	return (result);
}

int	colors(t_color *col)
{
	int	color;

	if (col->r > 255)
		col->r = 255;
	if (col->g > 255)
		col->g = 255;
	if (col->b > 255)
		col->b = 255;
	color = (col->r * 256 * 256) + (col->g * 256) + col->b;
	return (color);
}

int	get_pixel_color(t_vec *dir, t_scena *scena)
{
	t_close	cl;
	double	lim[2];

	lim[0] = 1;
	lim[1] = INFINITY;
	init_zero(&cl);
	cl = cl_inter(&scena->cams->orig, dir, scena, lim);
	if (cl.t == INFINITY)
		return (0);
	com_color_intens(&cl, dir, scena);
	return (colors(&cl.obj_col));
}
