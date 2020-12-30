#include "ft_printf.h"

int ft_putstr_prec(char *str, int prec)
{
    int count;

    count = 0;
    while (str[count] && count < prec)
        ft_putchar(str[count++]);
    return (count);
}

//
// Created by m on 30.12.2020.
//

