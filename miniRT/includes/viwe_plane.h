/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viwe_plane.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:04 by qdong             #+#    #+#             */
/*   Updated: 2021/03/21 17:13:42 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIWE_PLANE_H
# define VIWE_PLANE_H
// структура окна просмотра
typedef struct s_vplane
{
		float	widht;
		float	height;
		float	x_pixel;
		float	y_pixel;

}				t_vplane;

t_vplane		*get_vian_plane(float wedht, float height, float fov);
double			intersect(t_ray ray, t_general *objects);
double			sfera_intersect(t_ray ray, t_general *sfera);
double 			plane_intersect(t_ray ray, t_general *plane);
double			cy_intersect(t_ray ray, t_general *cylinder);
double			sq_intersect(t_ray ray, t_general *square);
double			tr_intersect(t_ray ray, t_general *triangle);
void 			ray_tracing(void *mlx , void *window, t_scena *scena);
#endif

