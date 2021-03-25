/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:56:59 by qdong             #+#    #+#             */
/*   Updated: 2021/03/23 17:00:26 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vec
{
	double x;
	double y;
	double z;
}				t_vec;

t_vec		new_vector(double x, double y, double z);
t_vec		substract_vec(t_vec vec1, t_vec vec2);
double		lingth_vec(t_vec vec);
t_vec		normalize_vec(t_vec vec);
double		dpv(t_vec vec1, t_vec vec2);
t_vec		cross_product(t_vec vec1, t_vec vec2);
t_vec		addit_vec(t_vec vec1, t_vec vec2);
t_vec		multip_vn(t_vec vec, double number);

#endif
