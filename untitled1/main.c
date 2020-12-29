#include "ft_printf.h"
#include <stdio.h>

int main()
{
    char *q = "-0.*";

    ft_printf("printf>> %s", q);
    printf("printf>> %s", q);
    return 0;
}

