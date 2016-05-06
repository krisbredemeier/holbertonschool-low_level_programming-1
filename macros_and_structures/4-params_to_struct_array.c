#include <stdlib.h>
#include "string_split.c"
#include "param_struct.h"

int get_length(char *c);
char *make_copy(char *c, int x);

struct Param *params_to_struct_array(int ac, char **av) {
  /* for each parameter (ac gives the amount) create a new
   struct that stores a pointer to the parameter (str), length 
   of the parameter, a copy of the string (copy), and a word table
  of the string (tab) */
  int i;
  Param **stru_arr;

  stru_arr = malloc(sizeof(Param) * ac);
  if (stru_arr == NULL) {
    return NULL;
  }

  for(i = 0; i < ac; i++) {
    stru_arr[i]->str = av[i];
    stru_arr[i]->length = get_length(av[i]);
    stru_arr[i]->copy = make_copy(av[i], stru_arr[i]->length);
    stru_arr[i]->tab = string_to_words(av[i]);
  }

  return stru_arr[0];
}

int get_length(char *c) {
  int i;
  
  for(i = 0; c[i] != '\0'; i++) {}
  
  return i;
}

char *make_copy(char *c, int x) {
  char *c2;

  c2 = malloc(sizeof(char) * (x + 1));
  if (c2 == NULL) {
    return NULL;
  }

  while(*c != '\0') {
    *c2++ = *c++;
  }
  
  return c2;
}
