/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 19:01:48 by qdong             #+#    #+#             */
/*   Updated: 2021/04/10 19:14:12 by qdong            ###   ########.fr       */
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

t_color mix_col(t_color *c1, t_color *c2)
{
	t_color result;

	result.r = c1->r * c2->r / 255;
	result.g = c1->g * c2->g / 255;
	result.b = c1->b * c2->b / 255;
	return (result);
}

t_color	col_sum(t_color *c1, t_color *c2)
{
	t_color result;

	result.r = c1->r + c2->r;
	result.g = c1->g + c2->g;
	result.b = c1->b + c2->b;
	return (result);
}
