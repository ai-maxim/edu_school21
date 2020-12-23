
#include "ft_printf.h"

void     ft_init_f(t_struct *f)
{
  
  f->minus = 0;
  f->zero = 0;
  f->dot = 0;
  f->star = 0;

  f->accuracy = 0;
  f->width = 0;
	f->precision_specified = 0;
	f->precision = 0;
	f->length = 0;
}

t_struct ft_reset_init(t_struct data)
{
   
}
