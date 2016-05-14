#include "shell_head.h"

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **argv, char **env) {
  char **str;
  char *input;
  int error;

  while(TRUE) {
    input = read_line(0);
    str = string_split(input, ' ');
    free(input);

    if (is_exit(str[0]) == 0) {
      free_str_arr(str);
      break;
    }

    if((error = execute_command(str, env)) == EXIT_FAILURE) {
      exit(error);
    }
    free_str_arr(str);
  }
  
  exit(0);

}

int is_exit(char *check) {
  char exit[] = "exit";
  int i;

  for (i = 0; i < 5; i++) {
    if (check[i] != exit[i]) {
      return (1);
    }
  }

  return (0);
}
