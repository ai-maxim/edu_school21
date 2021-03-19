#include "libft.h"

int	ft_strlen_arr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str != NULL)
		i++;
	return (i);
}
