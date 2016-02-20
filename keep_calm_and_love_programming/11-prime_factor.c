#include <stdio.h>
/*#define NUMBER 612852475143*/
#define NUMBER 1231952

int main(void) {
  long n = NUMBER;
  long div=2, ans = 0, maxFact;
  while(n) {
    if(n % div)
      div++;
    else {
      maxFact = n;
      n /= div;

      if(n == 1){
	printf("%ld\n",maxFact);
	ans = 1;
	break;
      }
    }
  }
  return 0;
}
