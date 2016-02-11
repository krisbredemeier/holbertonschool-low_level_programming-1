#include "my_functions.h"

void print_combination_1(void) {
  int ndx;
  print_char('0');
    for(ndx = 1; ndx <= 9; ndx++) {
      print_char(',');
      print_char(' ');
      print_char(ndx + '0');
    }
}
