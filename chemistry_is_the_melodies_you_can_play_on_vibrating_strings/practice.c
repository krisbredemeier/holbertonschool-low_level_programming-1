#include <stdio.h>

int main(void) {
  int x;

  x = 0x0000000;
  while (x <= 2000) {
    printf(" %x ", x);
    x += 30;
  }
  return 0;
}
