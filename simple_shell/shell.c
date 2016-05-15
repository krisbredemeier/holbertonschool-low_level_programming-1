#include "shell_head.h"

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **argv, char **env) {
  char **cmd;
  char *input;
  int error;

  signal(SIGINT, sig_handle_ctl_c);

  while(TRUE) {
    input = read_line(0);
    cmd = string_split(input, ' ');
    free(input);

    if((error = check_builtins(cmd)) != -1) {
      free_str_arr(cmd);
      continue;
    } 

    if((error = execute_command(cmd, env)) == EXIT_FAILURE) {
      exit(error);
    }
    free_str_arr(cmd);
  }
  
  exit(0);

}

void sig_handle_ctl_c(int sign) {
  char prompt[] = ">>> ";

  signal(sign, SIG_IGN);
  write(1 ,"\nPlease type 'exit' to quit.\n", 29);
  write(1, prompt, 4);
  signal(SIGINT, sig_handle_ctl_c);
}
