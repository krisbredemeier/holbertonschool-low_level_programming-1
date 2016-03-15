#include <stdio.h>

void reverse_array(int *a, int n) {
  int ndx, temp;
    
  n--;

  for (ndx = 0; ndx <= (n / 2); ndx++) {
    temp = *(a + ndx);
    *(a + ndx) = *(a + (n - ndx));
    *(a + (n - ndx)) = temp;
  }

}

