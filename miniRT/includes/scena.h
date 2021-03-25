/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:56:36 by qdong             #+#    #+#             */
/*   Updated: 2021/03/25 00:17:47 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENA_H
# define SCENA_H
# include "libft.h"
# include "minirt.h"


typedef	struct	s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct	s_closest
{
	double	t;
	t_vec	dot_inter;
	t_color	obj_col;
}				t_closest;

typedef struct	s_objs

{
	t_closest	(*intersect_funct)(t_vec *origin,t_vec *direction, void *data, double lim[2]);
	void		*data;
	void		*next;
	char		type;
}				t_objs;

typedef struct	s_ray
{
	t_vec	origin;
	t_vec	direction;
	t_vec	origin_inter; //  для света
	t_vec	direction_inter; //  для света
	char		type;
}				t_ray;


typedef struct	s_light
{
	t_vec			l_dot;
	double			brightness;
	t_color			color;
	struct s_light	*next;
}				t_light;

typedef struct	s_pl
{
	t_vec		center;
	t_vec		normal;
	t_color		color;
}				t_pl;

typedef struct	s_sp
{
	t_vec		center;
	double		diam;
	t_color		color;
}				t_sp;

typedef struct	s_sq
{
	t_vec		center;
	t_vec		normal;
	double		side_size;
	t_color		color;
}				t_sq;

typedef struct	s_cy
{
	t_vec		center;
	t_vec		dir;
	double		diam;
	double		height;
	t_color		color;
}				t_cy;

typedef struct	s_tr
{
	t_vec		c1;
	t_vec		c2;
	t_vec		c3;
	t_color		color;
}				t_tr;

typedef struct	s_perem
{
	t_vec		v1v0;
	t_vec		v2v0;
	t_vec		rov0;
	t_vec		n;
	t_vec		q;
	double		d;
	double		u;
	double		v;
	double		t;
} 				t_perem;

typedef struct	s_pars_per
{
	char		**arr;
	char		**arr1;
	char		**arr2;
	char		**arr3;
	char		**arr4;
}				t_pars_per;

typedef struct		s_scena
{
	t_camera	*cams;
	t_light		*light;
	int			widht;	// ширина окна
	int			height;	//высота окна
	double		brightness; //яркость ambient light
	t_color		color; // ambien light
	t_objs		*objs;
}				t_scena;

t_vec			get_coordinate(char **str);
t_color			get_color(char **str);
void			pars_data(char *rt, t_scena *scena);
void			parse_r(char *line, t_scena *scena);
void			parse_a(char *line, t_scena *scena);
void			parse_c(char *line, t_scena *scena);
void			parse_pl(char *line, t_scena *scena);
void			parse_l(char *line, t_scena *scena);
void			parse_sp(char *line, t_scena *scena);
void			parse_sq(char *line, t_scena *scena);
void			parse_cy(char *line, t_scena *scena);
void			parse_tr(char *line, t_scena *scena);

#endif
