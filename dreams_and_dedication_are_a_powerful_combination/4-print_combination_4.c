#include "my_functions.h"

/* 
 *
 */

void print_combination_4(void) {
  int x = 0, y = 1, next = 2;
  print_char('0');
  print_char('0');
  print_char(' ');
  print_char('0');  
  print_number(y++);
  while (x < 100) {
    while (y < 100) {
      print_char(',');
      print_char(' ');
      if (x < 10) {
	print_char('0');
      }
      print_number(x);
      print_char(' ');
      if (y < 10) {
	print_char('0'); 
      }
      print_number(y++);
    }
    y = next++;
    x++;
  }
}
