#include "my_functions.h"

void print_alphabet(void) {
  char letter = 'a';
  while(letter <= 'z') {
    print_char(letter++);
  } 
}
