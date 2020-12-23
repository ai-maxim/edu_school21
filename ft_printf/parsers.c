
#include "ft_printf.h"

void    pars_str(const char *format, t_struct *flags, va_list ap)
{
    while (format[flags->i] != '\0')
    {
        if (format[flags->i] == '%')
        {
            flags->i++;
            if (ft_strchr("#-+ .*0123456789hljz", format[flags->i]))
                ft_pars_modifiers(format, flags, ap);
            if (ft_strchr("sSpdDioOuUxXcCbr%", format[flags->i]))\
            {
                ft_printing(flags);
                if (flags->len == -1)
                    return ;
                ft_init_f(flags);
            }
        }
        else
            flags->len += write(flags->fd, &format[flags->i], 1);
        flags->i++;
    }
}
