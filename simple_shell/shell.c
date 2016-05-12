#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define PROMPT_SIZE 3
#define BUFF_SIZE 5

int read_line(void);

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **argv, __attribute__((unused)) char **env) {
  /* pid_t pid; */
  /* char *cmnd[] = {"/bin/echo", "Holberton", NULL}; */
  /* int status; */

  while(1) {
    if(read_line()) {
      return (1);
    }
  }
  
  return(0);

  /* if((pid = fork()) == -1) { */
  /*   perror("bad fork"); */
  /*   return (1); */
  /* } */
  /* if(pid == 0) { */
  /*   if (execve(cmnd[0], cmnd, env) == -1){ */
  /*     perror("bad execve"); */
  /*     return (1); */
  /*   } */
  /*   return(0); */
  /* } */
  /* else { */
  /*   wait(&status); */
  /*   if(status == 1) { */
  /*     perror("bad exit"); */
  /*     return (1); */
  /*   } */
  /*   else { */
  /*     return(0); */
  /*   } */
  /* } */
}

