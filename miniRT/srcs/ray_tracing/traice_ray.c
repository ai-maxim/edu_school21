/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traice_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:39 by qdong             #+#    #+#             */
/*   Updated: 2021/04/22 19:36:04 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	get_dir(t_scena *scena, int x, int y)
{
	t_vec	dir;
	double	radian;
	double	ratio;

	ratio = (double)scena->widht / (double)scena->height;
	radian = (double)scena->cams->fov * 0.5 * M_PI / 180;
	dir.x = (x + 0.5) * 2 * tan(radian) / (double)scena->widht;
	dir.y = (y + 0.5) * 2 * tan(radian) / (ratio * (double)scena->height);
	dir.z = 1;
	return (dir);
}

t_close	cl_inter(t_vec *orig, t_vec *ray, t_scena *scena, double *lim)
{
	t_close	closest;
	t_objs	*tmp;
	t_close	cl;

	tmp = scena->objs;
	closest.t = lim[1];
	while (tmp)
	{
		cl = tmp->inter_funk(orig, ray, tmp->data, lim);
		if (cl.t < closest.t)
			closest = cl;
		tmp = tmp->next;
	}
	return (closest);
}

void	com_color_intens(t_close *cl, t_vec *vec_d, t_scena *scena)
{
	double		i;
	t_light		*tmp;
	t_vec		l_vec;
	t_color		color;
	t_color		light_color;

	color = color_scalar_ret(scena->brightness, &scena->color);
	color = mix_col(&cl->obj_col, &color);
	tmp = scena->light;
	while (tmp)
	{
		i = 0;
		l_vec = substract_vec(tmp->l_dot, cl->dot_inter);
		tmp->l_vec = &l_vec;
		i = blic_and_diffuz(*cl, vec_d, scena, tmp);
		if (i)
		{
			light_color = color_scalar_ret(i, &tmp->color);
			light_color = mix_col(&cl->obj_col, &light_color);
			color = col_sum(&color, &light_color);
		}
		tmp = tmp->next;
	}
	cl->obj_col = color;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ray_tracing(void *mlx, t_scena *scena, t_data *imgs)
{
	int		color;
	int		x;
	int		y;
	t_vec	dir;

	imgs->img = mlx_new_image(mlx, scena->widht, scena->height);
	imgs->addr = mlx_get_data_addr(imgs->img, &imgs->bits_per_pixel,
			&imgs->line_length, &imgs->endian);
	x = (scena->widht * 0.5) * (-1);
	imgs->win_x = scena->widht;
	imgs->win_y = scena->height;
	while (x < scena->widht * 0.5)
	{
		y = scena->height * 0.5;
		while (y > scena->height * 0.5 * (-1))
		{
			dir = get_dir(scena, x, y);
			cam_go(&dir, scena->cams);
			color = get_pixel_color(&dir, scena);
			my_mlx_pixel_put(imgs, (int)(scena->widht * 0.5 + x),
				(int)(scena->height * 0.5 - y), color);
			y--;
		}
		x++;
	}
}
