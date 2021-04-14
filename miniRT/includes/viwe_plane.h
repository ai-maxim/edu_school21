/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viwe_plane.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:04 by qdong             #+#    #+#             */
/*   Updated: 2021/04/14 16:36:02 by qdong            ###   ########.fr       */
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

t_vplane	*get_vian_plane(double wedht, double height, double fov);
t_objs		*intersect(t_ray ray, t_list *objects, double min, double max);
t_close		sp_intersect(t_vec *orig,t_vec *dir, void *data, double lim[2]);
t_close		pl_intersect(t_vec *orig, t_vec *dir, void *data, double lim[2]);
t_close		cy_intersect(t_vec *orig, t_vec *dir, void *data, double lim[2]);
double		sq_intersect(t_ray ray, t_objs *sq, double *t);
t_close		tr_intersect(t_vec *orig, t_vec *dir, void *data, double lim[2]);
void 		ray_tracing(void *mlx , void *window, t_scena *scena, t_data *imgs);
t_vec		get_dir(t_scena *scena, int x, int y);

#endif
