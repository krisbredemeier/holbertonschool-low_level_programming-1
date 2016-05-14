#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define TRUE 1
#define FALSE 0

char *read_line(int);
void copy_string(char *, char *, int);

char **string_split(char *, char);
int count_chars(char *, char);
int count_words(char *, char);

int execute_command(char **, char **);
char *append_and_replace(char *, char *);

char *search_and_rescue(char *, char **);
char *find_command(char *, char **);
void free_str_arr(char **);

int is_exit(char *);
