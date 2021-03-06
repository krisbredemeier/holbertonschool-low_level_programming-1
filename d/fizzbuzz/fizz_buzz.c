#include <stdio.h>

/* LOOPS THROUGH NUMBERS 1-100, PRINTING "fizz"
 * IF THE NUMBER CAN BE EVENLY DIVIDED BY 3 AND
 * PRINTING "buzz" IF THE NUMBER CAN BE DIVIDED
 * BY 5, AND FINALLY PRINTING JUST THE NUMBER
 * IF NEITHER CASES APPLY.
 */
int main(void) {
  int ndx;
  for (ndx = 1; ndx <= 100; ndx++) {
    if (ndx % 3 == 0) {
      printf("fizz");
    }
    if (ndx % 5 == 0) {
      printf("buzz");
    }
    if (ndx % 3 != 0 && ndx % 5 != 0) {
      printf("%i", ndx);
    }
    if (ndx < 100) {
      printf(" ");
    }
  } 
  return 0;
}
