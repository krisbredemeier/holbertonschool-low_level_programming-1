#include <stdio.h>

void print_to_98(int n) {
  printf("%d", n);
  while (n < 98) {
    printf(", %d", ++n);
  }
  while (n > 98) {
    printf(", %d", --n);
  }
  printf("\n");
}
