#include "ft_printf.h"

int ft_putstr_chec(char *str, int chec)
{
    int count;

    count = 0;
    while (str[count] && count < chec)
        ft_putchar(str[count++]);
    return (count);
}
