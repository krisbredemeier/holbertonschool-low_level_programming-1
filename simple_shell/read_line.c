#include "shell_head.h"

#define PROMPT_SIZE 3
#define BUFF_SIZE 5

char *read_line(int fd) {
  char *bf, *temp;
  int size, i = 0;
 
  char prompt[] = ">>>";
  write(1, prompt, PROMPT_SIZE);

  bf = malloc(sizeof(char) * (BUFF_SIZE + 1));
 
  while (1) {
    size = read(fd, &(bf[i]), BUFF_SIZE);
    bf[i + size] = '\0';
    if (size == -1) {
      free(bf);
      perror("read bad");

      return NULL;
    }

    if (bf[i + size - 1] == '\n') {
      bf[i + size - 1] = '\0';
      /*      for(i = 0; bf[i] != '\0'; i++) {}
	      write(1, bf, i);*/
      
      return (bf);
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
  
}

void copy_string(char *source, char *dest) {
  while(*source != '\0') {
    *dest++ = *source++;
  }
  *dest = '\0';
}

