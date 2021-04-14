/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:56:54 by qdong             #+#    #+#             */
/*   Updated: 2021/04/14 14:32:16 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct	s_params
{
	void		*mlx;
	void		*win;
}				t_params;

void	error_exit(int code);
int		ft_perror(char *s);
char	error_invalid_map(char **line);
char	error_color(char **array);
int		strlen_arr(char **str);
char	error_invalid_file(int argc, char **argv);
void	ft_exit(char *s);
int		close_window(t_params *vars);
int		close_w(int	keycode, t_params	*vars);

#endif
