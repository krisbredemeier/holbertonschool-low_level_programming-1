#include "shell_head.h"
#include "shell_builtins.h"

/* check_builtin() recieves a string vector, and checks if the first element matches the
   name of any builtin commands. If found, it will execute the match's respective function and return
   the result of that function. If not found, it will return (-1). */
int check_builtins(char **cmd) {
  int i;
  builtin_f exec_builtin;
  char *builtins_v[] = {
    "exit",
    "env",
    "cd",
    "help",
    NULL
  };
  
  builtin_f builtins_f_v[] = {
    &builtin_exit,
    &builtin_env,
    &builtin_cd,
    &builtin_help,
    NULL
  };

  for (i = 0; builtins_v[i] != NULL; i++) {
    if ((string_compare(cmd[0], builtins_v[i])) == 0) {
      exec_builtin = builtins_f_v[i];
      return (exec_builtin(cmd));
    }
  }
  
  return (-1);
}

int string_compare(char *str1, char *str2) {
  int i;
  for(i = 0; str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0'; i++) {}
  if (str1[i] == '\0' && str2[i] == '\0') { 
    return (0);
  } 
  else {
    return (1);
  }
}
