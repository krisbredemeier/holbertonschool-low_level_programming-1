#include "my_functions.h"

void print_tebahpla(void) {
  char letter = 'z';
  while(letter >= 'a') {
    print_char(letter--);
  }
}
