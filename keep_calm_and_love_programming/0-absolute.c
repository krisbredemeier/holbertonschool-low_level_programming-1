#include <limits.h>

int absolute(int n) {
  if (n > INT_MIN && n < 0) {
    n *= -1;
  }
  return n;
}
