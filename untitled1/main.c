#include "ft_printf.h"
#include <stdio.h>

int main()
{
    char *q = "-0.*";

    printf("printf>> %c\n", 'q');
    ft_printf("ft_printf>> %c", 'q');
    return 0;
}