
#include "ft_printf.h"

int         ft_printf(const char *format, ...)
{
  va_list     array;
  const char  *str;
  int         out;

  va_start(array, format);
  if ((out = parser(format, &array)) == -1)
    return (-1);
  str = va_arg(array, char*);
  va_end(array);
  return(out);
}
