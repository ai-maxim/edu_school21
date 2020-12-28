
#include <stdio.h>

int main()
{
  char *q = "-0.*";

  printf("printf>> %s", q);
  return 0;
}

					make -C ./libft/
					cp libft/libft.a
					mv libft.a ${NAME}
