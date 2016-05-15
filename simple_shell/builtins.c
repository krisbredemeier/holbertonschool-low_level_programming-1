#include "shell_head.h"
#include "shell_builtins.h"

int builtin_exit(char **cmd) {
  int i;
  char *check;

  if (cmd[1] == NULL) {
    free_str_arr(cmd);
    exit(0);
  }
  if (cmd[2] != NULL) {
    print_string("Too many arguments\n");
    return (1);
  }
  check = cmd[1];
  for (i = 0; check[i] != '\0'; i++) {
    if (char_is_num(check[i])) {
      print_string("Argument must be a number\n");
      return (1);
    }
  }

  i = string_to_integer(cmd[1]);
  free_str_arr(cmd);
  exit(i);  
}

int builtin_help(char **cmd) {
  print_string("***Still under construction***\n");
  if(cmd[1] != NULL) {
    print_string(cmd[1]);
  }
  return (0);
}

int builtin_env(char **cmd) {
  print_string("***Still under construction***\n");
  if(cmd[1] != NULL) {
    print_string(cmd[1]);
  }
  return (0);
}

int builtin_cd(char **cmd) {
  print_string("***Still under construction***\n");
  if(cmd[1] != NULL) {
    print_string(cmd[1]);
  }
  return (0);
}
