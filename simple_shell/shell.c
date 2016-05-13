#include "shell_head.h"

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **argv, char **env) {
  char **str;

  while(1) {

    if(execute_command(str = string_split(read_line(0), ' '), env)) {
      free(str);
      return (1);
    }
    free(str);    
  }
  
  return(0);

}

