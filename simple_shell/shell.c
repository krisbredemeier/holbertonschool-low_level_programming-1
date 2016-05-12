#include "shell_head.h"

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **argv, __attribute__((unused)) char **env) {
  /* pid_t pid; */
  /* char *cmnd[] = {"/bin/echo", "Holberton", NULL}; */
  /* int status; */
  int i;
  char *str;

  while(1) {
    str = read_line(0);
    for(i = 0; str[i] != '\0'; i++) {}
    write(1, str, i);
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

