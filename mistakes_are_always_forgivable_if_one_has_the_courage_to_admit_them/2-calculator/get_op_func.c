int op_add(int, int);
int op_sub(int, int);
int op_mul(int, int);
int op_div(int, int);
int op_mod(int, int);

int (*get_op_func(char c))(int, int);

int main(void) {
  int x;

  x = get_op_func('*')(3, 2);

  return (x);
}


typedef int (*func_type)(int, int);

int (*get_op_func(char c))(int x, int y) {
  func_type ops[] = {&op_add, &op_sub, &op_mul, &op_div, &op_mod};
  char this_op[] = {'+', '-', '*', '/', '%'};

  int i;

  for(i = 0; i < 5; i++) {
    if (c == this_op[i]) {
      return (ops[i]);
    }
  }

  return 0;
}

int op_add(int x, int y){
  return (x + y);
}

int op_sub(int x, int y){
  return (x - y);
}

int op_mul(int x, int y){
  return (x * y);
}

int op_div(int x, int y){
  return (x / y);
}

int op_mod(int x, int y){
  return (x % y);
}
