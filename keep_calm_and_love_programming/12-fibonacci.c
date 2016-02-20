#include <stdio.h>

#define AMOUNT 98

signed long expon(int i) {
  signed long n = 1;
  while (i-- > 1) {
    n = n * 10;
  }
  return n;
}

int main(void) {
  signed long x1 = 1;
  signed long y1 = 1;
  signed long x2 = 0;
  signed long y2 = 0;
  signed long z1;
  signed long z2;
  int i = 1;
  int ndx = AMOUNT;

  printf("%ld", y1);

  while (ndx--) {
    /* check if overflow will occur on _1 */
    if ((x1 + y1) < 0) {
      x2 = x2 + (expon(i) * (x1 % 10));
      x1 /= 10;
      y2 = y2 + (expon(i) * (y1 % 10));
      y1 /= 10;
      i++;
    }
    /* stash full y value */
    z1 = y1;
    z2 = y2;
    /* add _1 sides together */
    y1 += x1;
    /* check if new digit to _2 */
    if ((x2 + y2) / expon(i)) {
      y1 += 1;
      y2 = x2 + y2 - expon(i);
    } else {
      y2 += x2;
    }
    /* update full x value */
    x1 = z1;
    x2 = z2;
    /* print depending on use of algorithm or not */
    if (y2 || x2) {
      printf("\n%ld%ld", y1, y2);
    } else {
      printf("\n%ld", y1);
    }
  }
  printf("\n");
  return 0;
}
