#include <stdio.h>
#include <stdlib.h>

int check_char(char);
char **string_to_words(char *);
int count_words(char *);
int count_chars(char *);

char **string_to_words(char *s) {
  int i, i2;
  char **ss;
  char *t;

  i = count_words(s);
  i2 = i;
  ss = malloc(sizeof(char *) * (i + 1));
  ss[i] = NULL;
  
  while(i) {
    if (check_char(*s)) {
      *ss = malloc(sizeof(char) * (count_chars(s) + 1));
    }
    t = *ss;
    while(check_char(*s)) {
      *t++ = *s++;
    }
    *t = '\0';
    while(check_char(*s) == 0) {
      s++;
    }
    ss++;
    i--;
  }
  return &(ss[-i2]);
}

int count_chars(char *s1) {
  int i;

  i = 0;
  while(check_char(*s1++)) {
    i++;
  }

  return i;
}

int check_char(char c) {
  if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
    return (1);
  }
  else {
    return (0);
  }
}

int count_words(char *s) {
  int i;

  i = 0;
  while(*s != '\0') {
    while (check_char(*s)) {
      s++;
    }
    if (check_char(s[-1])) {
      i++;
      s++;
    }
    if (s != '\0') {
      s++;
    }
  }
  return i;
}
