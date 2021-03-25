/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tr_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:34:48 by qdong             #+#    #+#             */
/*   Updated: 2021/03/23 18:15:54 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void		tr_intersect(t_ray ray, t_objects *tr, double *t)
// {
// 	t_perem p;
// 	t_vec 	mn;
// 	t_vec	mq;
// 	t_tr	*tri;

// 	tri = tr;
// 	p.v1v0 = substract_vec(tr., v0);
// 	p.v2v0 = substract_vec(v2, v0);
// 	p.rov0 = substract_vec(ray.origin, v0);
// 	p.n = cross_product(p.v1v0, p.v2v0);
// 	p.q = cross_product(p.rov0, ray.origin);
// 	p.d = 1.0 / dpv(ray.origin, p.n);
// 	mq = multip_vn(p.q, -1);
// 	mn = multip_vn(p.n, -1);
// 	p.u = p.d * dpv(mq, p.v2v0);
// 	p.v = p.d * dpv(p.q, p.v1v0);
// 	t[0] = p.d * dpv(mn, p.rov0);
// 	if (p.u < 0.0 || p.u > 1.0 || p.v < 0.0 || (p.u + p.v) > 1.0)
// 		t[0] = -1.0;
// }
