#include "shell_head.h"

/* string_to_words() takes a string and places all the
   words into an array of strings. */
char **string_to_words(char *s) {
  int i, i2;
  char **ss;
  char *t;
  i = count_words(s);
  ss = malloc(sizeof(char *) * (i + 1));
  if (ss == NULL) {
    return NULL;
  }
  ss[i] = NULL;
  i2 = 0;
  while(i2 < i) {
    if (*s != ' ' && *s != '\0') {
      ss[i2] = malloc(sizeof(char) * (count_chars(s) + 1));
      if (ss == NULL) {
        return NULL;
      }
      t = ss[i2];
      while(*s != ' ' && *s != '\0') {
        *t++ = *s++;
      }
      *t = '\0';
      while(*s == ' ' || *s == '\0') {
        s++;
      }
      i2++;
    }
    else {
      s++;
    }
  }
  return ss;
}

/* count_chars() counts how many chars are in a string */
int count_chars(char *s1) {
  int i;

  i = 0;
  while(*s1 != ' ' && *s1 != '\0') {
    s1++;
    i++;
  }

  return i;
}

/* count_words() counts how many words are in a string. A word must contain
   alphanumerical symbols only. */
int count_words(char *s) {
  int i;

  i = 0;
  while(*s != '\0') {
    if (*s != ' ') {
      i++;
    }
    while(*s != ' ' && *s != '\0') {
      s++;
    }
    while(*s == ' ' && *s != '\0') {
      s++;
    }
  }
  return i;
}
