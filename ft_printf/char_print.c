#include "ft_printf.h"

void    char_print(t_struct *flags, int s)
{
    if (flags->minus)
        flags->fd += write(1, &s, 1);
    width_print(flags, flags->width, 1, 0);
    if (!(flags->minus))
        flags->fd += write(1, &s, 1);
}