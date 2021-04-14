/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traice_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:57:39 by qdong             #+#    #+#             */
/*   Updated: 2021/04/14 18:59:09 by qdong            ###   ########.fr       */
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

t_close	cl_inter(t_vec *orig, t_vec ray, t_scena *scena, double *lim)
{
	t_close	closest;
	t_objs	*tmp;
	t_close	cl;

	tmp = scena->objs;
	closest.t = INFINITY;
	while (tmp)
	{
		cl = tmp->inter_funk(&scena->cams->orig, &ray, tmp->data, lim);
		if (cl.t < closest.t)
			closest = cl;
		tmp = tmp->next;
	}
	return (closest);
}

void	init_zero(t_close *cl)
{
	cl->t = INFINITY;
	cl->obj_col.r = 0;
	cl->obj_col.g = 0;
	cl->obj_col.b = 0;
}

void		com_color_intens(t_close *cl, t_vec *vec_d, t_scena *scena)
{
	float		i;
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
		i = compute_i(*cl, vec_d, scena, &l_vec, tmp);
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

int	colors(t_color *col)
{
	int	color;

	if (col->r > 255)
		col->r = 255;
	if (col->g > 255)
		col->g = 255;
	if (col->b > 255)
		col->b = 255;
	// color = (col->b * 256 * 256) + (col->g * 256) + col->r;
	color = (col->r * 256 * 256) + (col->g * 256) + col->b;
	return (color);
}

int	get_pixel_color(t_vec dir, t_scena *scena)
{
	t_close cl;
	double	lim[2];

	lim[0] = 1;
	lim[1] = MAX_DIST;
	init_zero(&cl);
	cl = cl_inter(&scena->cams->orig, dir, scena, lim);
	if (cl.t == INFINITY)
		return (0);
	com_color_intens(&cl, &dir, scena);
	return (colors(&cl.obj_col));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ray_tracing(void *mlx , void *window, t_scena *scena, t_data *imgs)
{
	int		color;
	int 	x;
	int 	y;
	t_vec	dir;

	imgs->img = mlx_new_image(mlx, scena->widht, scena->height);
	imgs->addr =
	mlx_get_data_addr(imgs->img, &imgs->bits_per_pixel, &imgs->line_length, &imgs->endian);
	x = (scena->widht * 0.5) * (-1);

	while (x < scena->widht * 0.5)
	{
		y = scena->height * 0.5;
		while (y > scena->height * 0.5 * (-1))
		{
			dir = get_dir(scena, x, y);
			dir	= normalize_vec(dir);
			// if (x == 0 && y == 0)
				color = get_pixel_color(dir, scena);
			my_mlx_pixel_put(imgs, (int)(scena->widht * 0.5 + x),
									(int)(scena->height * 0.5 - y), color);
			y--;
		}
		x++;
	}
	// mlx_put_image_to_window(mlx, window, imgs->img, 0, 0);
}
