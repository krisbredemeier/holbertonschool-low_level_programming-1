#include "shell_head.h"

int execute_command(char **cmd, char **env) {
  pid_t pid;
  int status;
  char *new;

  if((pid = fork()) == -1) {
    perror("bad fork");
    return (1);
  }
  if(pid == 0) {
    
    if((new = find_command(cmd[0], env)) == NULL) {
      perror("Cannot find command");
      free_str_arr(cmd);
      exit(EXIT_FAILURE);
    }

    cmd[0] = new;

    if (execve(cmd[0], cmd, env) == -1) {
      perror("bad execve");
      free_str_arr(cmd);
      exit(EXIT_FAILURE);
    }
    
    exit(EXIT_SUCCESS);
  }
  else {
    /* think about using waitpid() here instead */
    wait(&status);

    if(status == EXIT_FAILURE) {
      return(status);
    }   
    else {
      return(0);
    }
  }
  
  return (0);
}
