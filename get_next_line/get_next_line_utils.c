

#include "get_next_line.h"

int   ft_strlen(char *list)
{
  int i;

  i = 0;
  while (list[i] != '\0')
    i++;
  return (i);
}




char    *ft_strchr(char *line, int c)
{
  int   count;

  count = 0;
  while (line[count]) 
  {
    if (line[count] == (unsigned char)c)
      return ((char *)&line[count]);
    count++;
  }
  return (0);
}
