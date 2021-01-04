#include "ft_printf.h"

int     ft_done_width(int width, int minus, int zero)
{
    int count;

    count = 0;
    while (width - minus > 0)
    {
        if (zero)
            ft_putchar('0');
        else
            ft_putchar(' ');
        width -= 1;
        count++;
    }
    return (count);
}
