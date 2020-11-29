

#ifdef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include "stdlib.h"
#include "unistd.h"

typedef struct t_struct
{
  int   type;
  int   minus;
  int   plus;
  int   space;
  int   grill;
  int   zero;
  int   size;
  int   accuracy;
  int   poiter;

}       t_struct;

int     ft_printf(const char *, ...);

#endif
