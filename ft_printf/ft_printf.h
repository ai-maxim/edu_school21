
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
#include <unistd.h>

typedef struct s_struct
{
  int   i;
  int   len;
  int   fd;
  
  int   minus;
  int   zero;
  int   dot;
  int   star;
  int   accuracy;

  int   width;
	int   precision_specified;
	int   precision;
	int   length;

}       t_struct;

static void   print_str(char *str, t_struct *f);
static void   ft_printing(t_struct *data);
void          ft_init_f(t_struct *flags);
int           ft_printf(const char *, ...);


#endif
