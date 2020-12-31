#include "ft_printf.h"
#include <stdio.h>

int main()
{
    int i;
    char *q = "-0.*";

    i = 0;
    i = printf("printf>> %29s\n", q);
    printf("return: %d\n", i);
    i = ft_printf("ft_printf>> %29s\n", q);
    printf("return: %d", i);

//    printf("print>> %s\n", "string");
//    ft_printf("ft_printf>> %s\n", "string");

//    printf("print>> %c\n", 'w');
//    ft_printf("ft_printf>> %c\n", 'w');
    return 0;
}