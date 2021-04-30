/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:56:54 by qdong             #+#    #+#             */
/*   Updated: 2021/04/22 18:19:42 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "scena.h"

typedef struct s_params
{
	void		*mlx;
	void		*win;
	t_data		*img;
	t_scena		*scena;
}				t_params;

void			init_zero(t_close *cl);
void			error_exit(int code);
int				ft_perror(char *s);
char			error_invalid_map(char **line);
char			error_color(char **array);
char			error_invalid_file(int argc, char **argv);
void			ft_exit(char *s);
int				close_window(t_params *vars);
int				close_w(int	keycode, t_params	*vars);
int				get_color_bmp(t_data *p, int x, int y);
int				check_type_screen(char *str);
void			make_screen(t_data *ap);
void			cam_go(t_vec *dot, t_camera *cams);
void			camera_go(t_params *vars);
t_color			color_scalar_ret(double n, t_color *c);
t_color			mix_col(t_color *c1, t_color *c2);
t_color			col_sum(t_color *c1, t_color *c2);
int				colors(t_color *col);
void			check_normalaz(char *str1, char *str2, char *str3);
void			free_array(char **r);
void			free_scene(t_scena *scena);
void			free_all(t_params *p);

#endif
