#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define PROMPT_SIZE 3
#define BUFF_SIZE 5

void copy_string(char *, char *);

int read_line(void) {
  char prompt[] = ">>>";
  char *bf;
  char *temp;
  int size;
  int i;

  bf = malloc(sizeof(char) * (BUFF_SIZE + 1));

  write(1, prompt, PROMPT_SIZE);
  i = 0;
  while (1) {
    size = read(0, &(bf[i]), BUFF_SIZE);
    bf[i + size] = '\0';
    if (size == -1) {
      free(bf);
      perror("read bad");

      return (1);
    }

    if (bf[i + size - 1] == '\n') {
      for(i = 0; bf[i] != '\0'; i++) {}
      write(1, bf, i);

      return (0);
    }

    for(i = 0; bf[i] != '\0'; i++) {}
    temp = malloc(sizeof(char) * (i + 1));
    copy_string(bf, temp);
    
    free(bf);
    bf = malloc(sizeof(char) * (i + BUFF_SIZE + 1));
    copy_string(temp, bf); 
    free(temp);
     
    /* printf("i will not print"); */
    /* fflush(stdout); */    
    
  }
  
  return (0);
}

void copy_string(char *source, char *dest) {
  while(*source != '\0') {
    *dest++ = *source++;
  }
  *dest = '\0';
}

