#include "minirt.h"

t_vec	*new_vector(float x, float y, float z)
{
	t_vec	*vec;

	vec = malloc(sizeof(t_vec));
	if (!vec)
		error_exit(-1);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

t_vec	*substract_vec(t_vec *vec1, t_vec *vec2)
{
	t_vec	*result;

	result = new_vector(vec1->x - vec2->x, vec1->y - vec2->y, vec1->z - vec2->z);
	return (result);
}
