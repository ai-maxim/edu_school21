

#include "get_next_line.h"

int   ft_strlen(char *list)
{
  int i;

  i = 0;
  while (list[i] != '\0')
    i++;
  return (i);
}

char    ft_strdup(char *last_line)
{
  int   i;
  char  *array;

  i = 0;
  while (last_line[i] != '\0')
    i++;
  if(!(array = (char *)malloc((i + 1) * sizeof(char))))
    return (NULL);
  i = 0;
  while (last_line[i] != '\0') {
    array[i] = last_line[i];
    i++;
  }
  array[i] = '\0';
  return (array);
}

char  *ft_strjoin(char *s1, char *s2){
  char  *s3;
  int   i;
  int   j;

  if(!s1 || !s2)
    return (NULL);
  if (!(s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
    return (NULL);
  while (s1[i] != '\0') {
    s3[i] = s1[i];
    i++;
  }
  j = 0;
  while (s2[i] != '\0') {
    s3[i] = s2[j];
    i++;
    j++;
  }
  s3[i] = '\0';
  return (s3);
}

char    *ft_strchr(char *line, int c){
  int   count;

  count = 0;
  while (line[count]) {
    if (line[count] == (unsigned char)c)
      return ((char *)&line[count])
    count++;
  }
  return (0);
}
