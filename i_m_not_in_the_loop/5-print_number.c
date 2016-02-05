#include "my_functions.h"
#define MAX_LENGTH 100

int check_number(int num);
void give_char(char str[], int len);

void print_number(int num) {
  if ((num = check_number(num))) {
    char str[MAX_LENGTH];
    int i, rem, len = 0, n = num;
    while (n != 0) {
	len++;
	n /= 10;
    }
    for (i = 0; i < len; i++) {
	rem = num % 10;
	num = num / 10;
	str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
    give_char(str, len);
  }
}

void give_char(char str[], int len) {
  int i = 0;
  while(i < len) {
    print_char(str[i++]);
  }
}

int check_number(int num) {
  if (num < 0){
    num *= -1;
    print_char('-');
    return num;
  }
  if (num == 0) {
    print_char('0');
    return 0;
  }
  else {
    return num;
  }
}

