#include <stdio.h>
int factorial(int n);

int main(void)
{
  int r;

  r = factorial(0);
  printf("%d\n", r);
  r = factorial(-1);
  printf("%d\n", r);
  r = factorial(-2);
  printf("%d\n", r);
  r = factorial(30);
  printf("%d\n", r);
  return (0);
}
