/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:56:36 by qdong             #+#    #+#             */
/*   Updated: 2021/04/22 19:27:10 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENA_H
# define SCENA_H
# include "libft.h"
# include "minirt.h"
# include "camera.h"

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_close
{
	double		t;
	t_vec		dot_inter;
	t_color		obj_col;
	t_vec		normal;
}				t_close;

typedef struct s_objs
{
	t_close		(*inter_funk)(t_vec *orig, t_vec *dir,
					void *data, double lim[2]);
	void		*data;
	void		*next;
	char		type;
}				t_objs;

typedef struct s_light
{
	t_vec			l_dot;
	double			brightness;
	t_color			color;
	struct s_light	*next;
	t_vec			*l_vec;
}					t_light;

typedef struct s_pl
{
	t_vec		center;
	t_vec		normal;
	t_color		color;
}				t_pl;

typedef struct s_sp
{
	t_vec		center;
	double		diam;
	t_color		color;
	t_vec		oc;
	t_vec		bch;
	double		t[2];
}				t_sp;

typedef struct s_sq
{
	t_vec		center;
	t_vec		normal;
	double		side_size;
	t_color		color;
	t_vec		up;
	t_vec		right;
	t_vec		left;
	t_vec		d;
	t_vec		e;
	double		len;
}				t_sq;

typedef struct s_cy
{
	t_vec		center;
	t_vec		dir;
	double		diam;
	double		height;
	t_color		color;
	double		m[3];
	double		a;
	double		b;
	double		c;
	double		discr;
	double		t[2];
}				t_cy;

typedef struct s_tr
{
	t_vec		c1;
	t_vec		c2;
	t_vec		c3;
	t_color		color;
}				t_tr;

typedef struct s_matrix
{
	t_vec		right;
	t_vec		forw;
	t_vec		orig;
	t_vec		up;

}				t_matrix;

typedef struct s_perem
{
	t_vec		v1;
	t_vec		v2;
	t_vec		vec;
	t_vec		tvec;
	double		c;
	double		a;
	double		b;
	double		det;
	double		t;
}				t_perem;

typedef struct s_pars_per
{
	char		**arr;
	char		**arr1;
	char		**arr2;
	char		**arr3;
	char		**arr4;
}				t_pars_per;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			win_x;
	int			win_y;
}				t_data;

typedef struct s_scena
{
	t_camera	*cams;
	t_light		*light;
	int			widht;
	int			height;
	double		brightness;
	t_color		color;
	t_objs		*objs;
	int			ambient;
	int			cam_flag;
}				t_scena;

typedef struct s_arg
{
	t_vec		*orig;
	t_vec		*dir;
	void		*data;
	double		lim0;
	double		lim1;
	double		a;
	double		b;
	double		c;
	double		m;
	t_vec		xyz;
	t_vec		w;
}				t_arg;

void			check_line(char *line, t_scena *scena);
t_vec			get_coordinate(char **str);
t_color			get_color(char **str);
void			pars_data(char *rt, t_scena *scena);
void			parse_r(char *line, t_scena *scena);
void			parse_a(char *line, t_scena *scena);
void			parse_c(char *line, t_scena *scena);
void			check_parse_c0(char *line, t_camera	*new_cam);
void			check_parse_c1(t_camera	*tmp,
					t_camera	*new_cam, t_scena *scena);
void			parse_l(char *line, t_scena *scena);
void			parse_l_color(t_light *new_light, char **array);
void			parse_pl(char *line, t_scena *scena);
void			parse_sp(char *line, t_scena *scena);
void			parse_sq(char *line, t_scena *scena);
void			parse_cy(char *line, t_scena *scena);
void			parse_tr(char *line, t_scena *scena);
t_color			mix_col(t_color *c1, t_color *c2);
t_color			color_scalar_ret(double n, t_color *c);
t_color			col_sum(t_color *c1, t_color *c2);
void			com_color_intens(t_close *cl, t_vec *vec_d, t_scena *scena);
int				get_pixel_color(t_vec *dir, t_scena *scena);
t_close			cl_inter(t_vec *orig, t_vec *ray, t_scena *scena, double *lim);
double			blic_and_diffuz(t_close cl, t_vec *vec_d,
					t_scena *scena, t_light *lgt);
double			diffuse_intens(t_close cl, t_vec *l_vec, double light_i);
double			blic_intens(t_close cl, t_vec *l_vec,
					t_vec *vec_d, double light_i);
void			init_zero(t_close *cl);
void			invert_normal(t_vec *norm, t_vec p, t_vec *o);

#endif
