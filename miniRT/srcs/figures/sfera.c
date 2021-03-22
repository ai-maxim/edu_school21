/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfera.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:22 by qdong             #+#    #+#             */
/*   Updated: 2021/03/21 20:18:49 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_general		*new_sfera(t_vec center, float radius)
{
	t_general	*sfera;

	sfera = malloc(sizeof(t_general));
	if (!sfera)
		error_exit(-1);
	sfera->center = center;
	sfera->radius = radius;
//	sfera->color = color;
	sfera->type = 's';
	sfera->next = NULL;
	return (sfera);
}
