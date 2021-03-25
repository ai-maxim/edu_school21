/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viwe_plane.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:04 by qdong             #+#    #+#             */
/*   Updated: 2021/03/24 18:55:48 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIWE_PLANE_H
# define VIWE_PLANE_H
// структура окна просмотра
typedef struct s_vplane
{
		double	widht;
		double	height;
		double	x_pixel;
		double	y_pixel;

}				t_vplane;

t_vplane		*get_vian_plane(double wedht, double height, double fov);
t_objs			*intersect(t_ray ray, t_list *objects, double min, double max);
void			sp_intersect(t_ray ray, t_objs *sp, double *t);
void 			pl_intersect(t_ray ray, t_objs *pl, double *t);
double			cy_intersect(t_ray ray, t_objs *cy, double *t);
double			sq_intersect(t_ray ray, t_objs *sq, double *t);
void			tr_intersect(t_ray ray, t_ray direction, t_vec v0, t_vec v1, t_vec v2, double *t);
void 			ray_tracing(void *mlx , void *window, t_scena *scena);

#endif
