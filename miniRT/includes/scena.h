/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:56:36 by qdong             #+#    #+#             */
/*   Updated: 2021/03/21 18:08:30 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENA_H
# define SCENA_H
#include "minirt.h"

typedef struct	s_general
{
	void				*content;
	struct s_general	*next;
	t_vec			center; // центр фигур
	t_vec			direction; // направление фигуры
	t_vec			normal; // направление по умолчанию по оси z
	t_vec			origin;
	float			fov; //ugol obzora
	float			radius;
	float			height;
	float			side_size;
	int				color;
	t_vec			c;
	t_vec			c1;
	t_vec			c2;
	char 			type;
}					t_general;

typedef struct	s_ray
{
	t_vec		origin;
	t_vec		direction;
	t_vec		origin_inter; //  для света
	t_vec		direction_inter; //  для света
	
	char		type;
}				t_ray;

typedef struct	s_light
{
	float		x;
	float		y;
	float		z;
	float		brightness;
	int			color;
}				t_light;

typedef struct	s_cam
{
	t_vec		origin;
	t_vec		direction;
	float		fov;
	float		x;
	float		y;
	float		z;
	int			color;
}				t_cam;

typedef struct	s_pl
{
	t_vec		center;
	t_vec		normal;
	float		x;
	float		y;
	float		z;
	int			color;
}				t_pl;

typedef struct	s_sp
{
	t_vec		center;
	float		radius;
	float		x;
	float		y;
	float		z;
	int			color;
}				t_sp;

typedef struct	s_sq
{
	t_vec		center;
	t_vec		normal;
	float		side_size;
	float		x;
	float		y;
	float		z;
	int			color;
}				t_sq;

typedef struct	s_cy
{
	t_vec		center;
	t_vec		direction;
	float		radius;
	float		height;
	float		x;
	float		y;
	float		z;
	int			color;
}				t_cy;

typedef struct	s_tr
{
	t_vec		c;
	t_vec		c2;
	t_vec		c3;
	float		x_c;
	float		y_c;
	float		z_c;
	float		x_c2;
	float		y_c2;
	float		z_c2;
	float		x_c3;
	float		y_c3;
	float		z_c3;
	int			color;
}				t_tr;

typedef struct	s_matrix
{
	float x;
	float y;
	float z;
}				t_matrix;

typedef struct s_scena
{
	void				*content;
	struct s_scena		*next;
	t_camera	*cams;
	t_general	*objects;
	t_cam		camera;
	t_light		light;
	t_pl		pl;
	t_sp		sp;
	t_sq		sq;
	t_cy		cy;
	t_tr		tr;
	float		center;
	float		normal;
	int			radius;
	int			widht;	// ширина окна
	int			height;	//высота окна
	float		origin;
	int			direction;
	float		fov;
	float		side_size;
	float		brightness; //яркость
	// t_vec		c;
	// t_vec		c1;
	// t_vec		c2;
	int			color;
	char		type;
}				t_scena;

t_scena			*new_scena(t_camera *cams, t_general *object);
t_general		*new_sfera(t_vec center, float radius);
t_general		*new_plane(t_vec center, t_vec normal);
t_general		*new_cylinder(t_vec center, t_vec direction, float radius, float height);
t_general 		*new_square(t_vec center, t_vec normal, float side_size);
t_general		*new_triangle(t_vec c, t_vec c1, t_vec c2, int color);
t_camera		*new_camera(t_vec origin, t_vec direction, float fov);
int				colors(char *num, t_scena scena);
//int				nums(char *num, t_scena scena);
void			*pars_data(t_general *name, t_scena scena);
void			parse_r(char *line, t_scena scena);
void			parse_a(char *line, t_scena scena);
void			parse_c(char *line, t_scena scena);
void			parse_l(char *line, t_scena scena);
void			parse_pl(char *line, t_scena scena);
void			parse_sp(char *line, t_scena scena);
void			parse_sq(char *line, t_scena scena);
void			parse_cy(char *line, t_scena scena);
void			parse_tr(char *line, t_scena scena);

#endif
