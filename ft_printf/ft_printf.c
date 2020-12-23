
#include "ft_printf.h"

int         ft_printf(const char *format, ...)
{
  va_list     ap;
  const char  *str;
  int         out;

  va_start(ap, format);
  if ((out = parser(format, &ap)) == -1)
    return (-1);
  str = va_arg(ap, char*);
  va_end(ap);
  return(out);
}
