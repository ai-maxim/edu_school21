/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viwe_plane.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:04 by qdong             #+#    #+#             */
/*   Updated: 2021/04/21 12:56:39 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIWE_PLANE_H
# define VIWE_PLANE_H
typedef struct s_vplane
{
		double	widht;
		double	height;
		double	x_pixel;
		double	y_pixel;

}				t_vplane;

t_vplane	*get_vian_plane(double wedht, double height, double fov);
t_objs		*intersect(t_ray ray, t_list *objects, double min, double max);
t_close		sp_intersect_0(t_vec *orig, t_vec *dir, void *data, double lim[2]);
t_close		sp_intersect_1(t_vec *orig, t_vec *dir, void *data, double lim[2]);
t_close		sp_intersect(t_vec *orig,t_vec *dir, void *data, double lim[2]);
t_close		pl_intersect(t_vec *orig, t_vec *dir, void *data, double lim[2]);
t_close		cy_intersect(t_vec *orig, t_vec *dir, void *data, double lim[2]);
t_close		sq_intersect(t_vec *orig, t_vec *dir, void *data, double lim[2]);
void		tr_intersect_1(t_vec *dir, void *data, t_perem *p);
void		tr_intersect_2(t_perem *p, void *data, t_vec *orig);
void		init_arg(t_vec *orig, t_vec *dir, double lim[2], t_arg *arg);
void		tr_intersect_3(void *data, t_perem p, t_close *cl, t_arg *arg);
t_close		tr_intersect(t_vec *orig, t_vec *dir, void *data, double lim[2]);
void 		ray_tracing(void *mlx , void *window, t_scena *scena, t_data *imgs);
t_vec		get_dir(t_scena *scena, int x, int y);

#endif
