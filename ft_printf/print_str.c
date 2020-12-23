#include "ft_printf.h"
#include "libft/libft.h"

static void print_str(char *str, t_struct *f)
{
    int strlen;

    if (!str)
        str = NULL;
    strlen = ft_strlen(str);
    if (f->precision_specified && strlen > 0 && strlen > f->precision)
        strlen = f->precision;
    f->len += write(f->fd, str, strlen);
    while (f->width > strlen)
    {
        f->len += write(f->fd, " ", 1);
        f->width--;
    }
}

static void ft_print_str_right(char *str, t_struct *f)
{
    int strlen;

    if (!str)
        str = NULL;
    strlen = ft_strlen(str);
    if (f->precision_specified && strlen > 0 && strlen > f->precision)
        strlen = f->precision;
    while (f->width > *str)
    {
        if (f->zero)
            f->len += write(f->fd, "0", 1);
        else
            f->len += write(f->fd, " ", 1);
        f->width--;
    }
    f->len += write(f->fd, str, strlen);
}

//static void ft_print_wide_str_left(wchar_t *wstr, t_struct *f)
//{
  //  int wstrsize;

//}
