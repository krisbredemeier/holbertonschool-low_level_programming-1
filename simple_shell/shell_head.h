#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *read_line(int);
void copy_string(char *, char *);

char **string_to_words(char *);
int count_chars(char *);
int count_words(char *);
