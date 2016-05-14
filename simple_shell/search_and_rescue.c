#include "shell_head.h"

char *search_and_rescue(char *search, char **env) {
  int i;
  char *check;
  if (search == NULL) {
    perror("No search criteria");
    return NULL;
  }

  while(*env != NULL) {
    i = 0;
    check = *env;
    while(check[i] == search[i] && check[i] != '=') {
      i++;
    }
    if (check[i] == '=') {
      return &(check[i + 1]);
    }
    env++;
  }
  
  return NULL;
}

char *find_command(char *exec, char **env) {
  char **dir_arr;
  char *dir_path;
  char *path;
  struct stat stat_strut;
  int i;

  path = search_and_rescue("PATH", env);
  dir_arr = string_split(path, ':');

  for(i = 0; dir_arr[i] != NULL; i++) {
    dir_path = append_and_replace(exec, dir_arr[i]);

    if ((stat(dir_path, &stat_strut)) == 0) {
      free(exec);
      return dir_path;
    }
    free(dir_path);
  }

  free_str_arr(dir_arr);
  return NULL;

}

char *append_and_replace(char *str, char *dir) {
  int i, i2, i3;
  char *new;

  /* i is an index for the size of command */
  for (i = 0; str[i] != '\0'; i++) {}
  /* i3 is an index for the size of directory */
  for (i3 = 0; dir[i3] != '\0'; i3++) {}
  
  new = malloc(sizeof(char) * (i3 + i + 2));
  
  /* i is reset to be the index for the new string */
  for (i = 0; dir[i] != '\0'; i++) {
    new[i] = dir[i];
  }
  new[i] = '/';
  i++;

  /* i2 is now used as an index for the command string */
  for (i2 = 0; str[i2] != '\0'; i2++, i++) {
    new[i] = str[i2];
  }

  new[i] = '\0';
  /* printf("\n\nadditional string length: %d\nold string length: %d\nnew string length: %d (additional + old + 2)\n\n", i3, i2, (i + 1));
     fflush(stdout);*/

  return (new);
}

void free_str_arr(char **str_arr) {
  int i;

  for (i = 0; str_arr[i] != NULL; i++) {
    free(str_arr[i]);
  }
  
  free(str_arr);
}
