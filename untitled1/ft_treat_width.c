#include "ft_printf.h"

int ft_trat_width(int width, int minus, int has_zero)
{
    int count_simvol;

    count_simvol = 0;
    while (width - minus > 0)
    {
        if (has_zero)
            ft_putchar('0');
        else
            ft_putchar(' ');
        width -= 1;
        count_simvol++;
    }
    return (count_simvol);
}

//
// Created by m on 30.12.2020.
//

