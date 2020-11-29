#include <stdio.h>

int main(){
  printf("|%-10d| \n", 555);
  printf("|%10.2fd|\n", 555);
  printf("|%-10d|\n", 555);
  printf("%s" "%10d\n", "Words:", 59);
  printf("%s" "%10d\n", "Letters:", 1004);
  printf("%s" "%10d\n", "Digits:", 8);
  return (0);
}
