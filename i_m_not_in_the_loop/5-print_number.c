#include "my_functions.h"
#define MAX_LENGTH 100


/*
print_number takes an int, and first passes it to check_number                                           
to determine if it is 0, a negative number, or the minimum. print_number then                            
loops through the int dividing it by 10 until it equals 0, and                                           
indexes it's iterations. This determines how many digits the                                             
original int is. It then loops through each digit, uses the modulus                                      
to determine what that digit is, and fills a char array with the ASCII                                   
char number equivalent to that int. Finally it gives the array to                                        
the function give_char which prints out each array index.   
 */

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
  if (num == -2147483648) {
    give_char("-2147483648", 12);
    return 0;
  }
  else if (num < 0){
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

