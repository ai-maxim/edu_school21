#include "ft_printf.h"
#include <stdio.h>

int main()
{
    int n = 156;
    int *np = &n;
//    int i;
//    char *q = "-0.*";
//    char *q = "hi low";

//    i = 0;
//    i = printf("printf>> |%29s|\n", q);
//    printf("return: %d\n", i);
//    printf("return: %d", i);
//    i = ft_printf("ft_printf>> |%29s|\n", q);

    // printf("\nEXAMPLE \n|%.7s|\n ", q);
    // ft_printf("\nEXAMPLE \n|%.7s|\n ", q);

    printf("%-15p\n", np);
//    ft_printf("%p\n", np);

    // i = ft_printf("%.5d\n", 2);
    // printf("if = %d\n", i);
    // i = printf("%.5d\n", 2);
    // printf("io = %d\n", i);


//    printf("print>> %s\n", "string");
//    ft_printf("ft_printf>> %s\n", "string");

//    printf("print>> %c\n", 'w');
//    ft_printf("ft_printf>> %c\n", 'w');

//    printf("print>> %c % %d %i %u %x %X\n", 'w', "string", 21, 42, );
//    ft_printf("ft_printf>> %c\n", 'w');
    return 0;
}
