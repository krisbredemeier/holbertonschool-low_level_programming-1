#include "my_functions.h"

void print_base16(void) {
  char i = '0';
  while(i <= 'F') {
    print_char(i++);
    if (i == ('9' + 1)) {
      i = 'A';
    }
  }
}
