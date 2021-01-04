#include "ft_printf.h"
#include <stdio.h>

int main()
{
//    int i;
//    char *q = "-0.*";
//    char *q = "hi low";

//    i = 0;
//    i = printf("printf>> |%29s|\n", q);
//    printf("return: %d\n", i);
//    i = ft_printf("ft_printf>> |%29s|\n", q);
//    printf("return: %d", i);

    // printf("\nEXAMPLE \n|%.7s|\n ", q);
    // ft_printf("\nEXAMPLE \n|%.7s|\n ", q);

    // printf("%05%\n");
    // ft_printf("%05%\n");

    printf("%-4d", -21);
    ft_printf("%-4d", -21);

//    printf("print>> %s\n", "string");
//    ft_printf("ft_printf>> %s\n", "string");

//    printf("print>> %c\n", 'w');
//    ft_printf("ft_printf>> %c\n", 'w');

//    printf("print>> %c % %d %i %u %x %X\n", 'w', "string", 21, 42, );
//    ft_printf("ft_printf>> %c\n", 'w');
    return 0;
}
