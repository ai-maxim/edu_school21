/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tr_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:34:48 by qdong             #+#    #+#             */
/*   Updated: 2021/03/21 17:16:16 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double			tr_intersect(t_ray ray, t_general *triangle)
{
	float	t;
	t_vec	cam_tr;

	t = plane_intersect(cam, ray, triangle);
	cam_tr = cross_product(triangle->c, triangle->c1);

	return (t);
}
