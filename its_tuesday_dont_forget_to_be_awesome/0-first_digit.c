#include <limits.h>

int first_digit(int n) {
  int i;
  i = n;
  if (n < 0 && n > INT_MIN) {
    n *= -1;
  }
  else if (n == INT_MIN) {
    n /= 10;
    n *= -1;
  }
  while(n) {
    i = n;
    n /= 10;
  }
  return i;
}
