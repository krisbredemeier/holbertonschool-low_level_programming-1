#include <stdio.h>
#define NUMBER 612852475143

int main(void) {
  long n = NUMBER;
  long divideBy = 2;
  long largest;
  while(n) {
    if(n % divideBy)
      divideBy++;
    else {
      largest = n;
      n /= divideBy;
      if(n == 1){
	printf("%ld\n", largest);
        n = 0;
      }
    }
  }
  return 0;
}
