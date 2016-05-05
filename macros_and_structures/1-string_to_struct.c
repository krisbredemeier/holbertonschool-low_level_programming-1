#include <stdlib.h>
#include "str_struct.h"

/* string_to_struct stores a string and that string's
size into a struct.
 */
struct String *string_to_struct(char *str) {
  int i;
  struct String *xxx;

  xxx = malloc(sizeof(struct String));
  if (xxx == NULL) {
    return NULL;
  }

  xxx->str = str;

  i = 0;
  while(str[i] != '\0') {
    i++;
  }
  
  xxx->length = i;
  
  return xxx;
}
