#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vec
{
	float x;
	float y;
	float z;
}				t_vec;

t_vec	*new_vector(float x, float y, float z);

#endif
