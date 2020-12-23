#include "ft_printf.h"

static void     print_char_left(unsigned char c, t_struct *f)
{
    f->len += write(f->fd, &c, 1);
    while (f->width > 1)
    {
        f->len += write(f->fd, " ", 1);
        f->width--;
    }
}

static void     print_char_right(unsigned char c, t_struct *f)
{
    while (f->width > 1)
    {
        if (f->zero)
            f->len += write(f->fd, "0", 1);
        else
            f->len += write(f->fd, " ", 1);
        f->width--;
    }
    f->len += write(f->fd, &c, 1);
}