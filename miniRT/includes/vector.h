/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:56:59 by qdong             #+#    #+#             */
/*   Updated: 2021/03/21 13:44:17 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vec
{
	float x;
	float y;
	float z;
}				t_vec;

t_vec		new_vector(float x, float y, float z);
t_vec		substract_vec(t_vec vec1, t_vec vec2);
float		lingth_vec(t_vec vec);
t_vec		normalize_vec(t_vec vec);
float		dot_product_vec(t_vec vec1, t_vec vec2);
float		cross_product(t_vec vec1, t_vec vec2);
t_vec		addit_vec(t_vec vec1, t_vec vec2);
t_vec		multiply_vec_num(t_vec vec, float number);

#endif
