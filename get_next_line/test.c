#include <stdio.h>

int	f1(int j)
{
	j = 110;
	return (j);
}

void	f2(int *i)
{
	*i = *i * 2;
}

int main(void)
{
	int i;

	i = 5;
	i = f1(i);
	f2(&i);
	printf("%d\n", i);
//	return (0);
}
