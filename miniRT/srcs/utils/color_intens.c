/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_intens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 19:17:47 by qdong             #+#    #+#             */
/*   Updated: 2021/04/14 15:14:25 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	diffuse_intens(t_close cl, t_vec *l_vec, double light_i)
{
	double	n_dot;
	double i;

	i = 0;
	n_dot = dpv(cl.normal, *l_vec);
	if (n_dot > 0)
		i = light_i * n_dot / (lingth_vec(cl.normal) * lingth_vec(*l_vec));
	return (i);
}

double	spec_intens(t_close cl, t_vec *l_vec, t_vec *vec_d, double light_i)
{
	t_vec	vec_v;
	double	dot_v;
	t_vec	tmp;
	t_vec	vec_r;

	vec_v = *vec_d;
	vec_v = multip_vn(vec_v, -1);
	dot_v = 2 * dpv(cl.normal, *l_vec);
	tmp = cl.normal;
	tmp = multip_vn(tmp, dot_v);
	vec_r = substract_vec(tmp, *l_vec);
	dot_v = dpv(vec_r, vec_v);
	if (dot_v > 0)
	{
		dot_v = light_i *
		pow(dot_v / (lingth_vec(vec_r) * lingth_vec(vec_v)), 300);
		return (dot_v);
	}
	return (0);
}

double compute_i(t_close cl, t_vec *vec_d, t_scena *scena,
					t_vec *l_vec, t_light *lgt)
{
	double	i;
	t_close	tl;
	double	lim[2];

	i = 0;
	lim[0] = 0.0001;
	lim[1] = 1;
	tl = cl_inter(&cl.dot_inter, *l_vec, scena, lim);
	if (tl.t != INFINITY)
		return (i);
	i += diffuse_intens(cl, l_vec, lgt->brightness);
	i += spec_intens(cl, l_vec, vec_d, lgt->brightness);
	return (i);
}
