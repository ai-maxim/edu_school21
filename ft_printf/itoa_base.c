
#include "ft_printf.h"

static	int	len(int n)
{
	int len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

char	*itoa_base(int64_t n, t_struct *flags)
{
	int i;
	char *str;
	int f;

	i = len(n);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (n != 0)
	{
		f = n % 16;
		if(f >= 0 && f <= 9)
			str[i] = f + '0';
		else if (flags->type == 'x')
			str[i] = f + 'W';
		else
			str[i] = f + 55;
		n = n / 16;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int main()
{
	t_struct test;

	test.type = 'x';
	printf("%s", itoa_base(8, &test));
	return 0;
}
