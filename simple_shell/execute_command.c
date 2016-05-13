#include "shell_head.h"

int execute_command(char **cmd, char **env) {
  pid_t pid;
  int status;

  if((pid = fork()) == -1) {
    perror("bad fork");
    return (1);
  }
  if(pid == 0) {
    
    if((cmd[0] = find_command(cmd[0], env)) == NULL) {
      perror("Cannot find comand");
      return (1);
    }

    if (execve(cmd[0], cmd, env) == -1) {
      perror("bad execve");
      return (1);
    }
    return(0);
  }
  else {
    wait(&status);
    if(status == 1) {
      perror("bad exit");
      return (1);
    }
    else {
      return(0);
    }
  }
  
  return 0;
}
 


/* void print_array_of_strings(char **a) { */
/*   if (*a == NULL) { */
/*     printf("\n"); */
/*   } */
/*   else { */
/*     print_string(*a); */
/*     printf(" "); */
/*     a++; */
/*     print_array_of_strings(a); */
/*   } */
/* } */

/* void print_string(char *s) { */
/*   if (*s == '\0') { */
/*     return; */
/*   } */
/*   else { */
/*     printf("%c", *s); */
/*     s++; */
/*     print_string(s); */
/*   } */
/* } */
