#include "shell_head.h"

 /* int main(__attribute__((unused)) int ac, __attribute__((unused)) char **argv, char **env) { */
 /*  char *result; */
 /*  char *search; */
 /*  search = argv[1]; */
  
 /*  if((result = search_and_rescue(search, env)) == NULL) { */
 /*    perror("search and rescue bad"); */
 /*    return (1); */
 /*  } */

 /*  printf("%s\n", result); */

 /*  return(0); */
 /*  } */

/* search for variable within **env */
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
  printf("%s\n", path);
  dir_arr = string_split(path, ':');

  for(i = 0; dir_arr[i] != NULL; i++) {
    dir_path = append_and_replace(exec, dir_arr[i]);

    printf("1%s\n", dir_path);
    fflush(stdout);
    free(dir_path);
    
    /* if ((stat(dir_path, &stat_strut)) == 0) { */
    /*   return dir_path; */
    /* } */
  }

  free(dir_arr);
  return NULL;

}

char *append_and_replace(char *str, char *dir){
  int i, i2, i3;
  char *new;

  for (i = 0; str[i] != '\0'; i++) {}
  for (i3 = 0; dir[i3] != '\0'; i3++) {}
  
  new = malloc(sizeof(char) * (i3 + i + 2));
  new[i + i3 + 1] = '\0';
  
  for (i = 0; dir[i] != '\0'; i++) {
    new[i] = dir[i];
  }
  new[i++] = '/';
  for (i2 = 0; str[i2] != '\0'; i2++, i++) {
    new[i] = str[i2];
  }
  free(str);
  return (new);
}
