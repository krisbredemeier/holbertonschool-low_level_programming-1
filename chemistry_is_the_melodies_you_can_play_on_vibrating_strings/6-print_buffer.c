#include <stdio.h>

/*void print_string(char *str);*/
void ripple(char*);
void increment_memory(char*);
void print_buffer(char*, int);
void convert_to_hex(char*, int);
void print_mod_string(char*, int);

int main(void) {
  char str[] = "This is a string!\0And this is the rest of the #buffer :)\1\2\3\4\5\6\7#cisfun\n\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x20\x21\x34\x56#pointersarefun #infernumisfun\n";
  
    
  print_buffer(str, sizeof(str));
  return 0;
}

void convert_to_hex(char *b, int size) {
  char *c; 
  char res[] = "00";
  c = b;
  
  while (size-- > 0) {
    res[0] = *c / 16 + '0';
    res[1] = *c % 16 + '0';
    if (res[0] > '9') {
      res[0] += 39;
    } 
    if (res[1] > '9') {
      res[1] += 39;
    }
    printf("%s", res);
    if (size % 2 == 0) {
      printf("%c", ' ');
    }
    c++;
  }
}

void print_buffer(char *b, int size) {
  /*char line[47];*/
  char memory[] = "00000000: ";
  int s;

  printf("%s\n", b);
  
  while (size > 0) {
    if ((size - 10) >= 0) {
      s = 10;
    } 
    else {
      s = size;
    }
    printf("\n%s", memory);
    convert_to_hex(b, s);
    print_mod_string(b, s);
    increment_memory(memory);
    size -= 10;
    b += 10;
  }
}

void print_mod_string(char *c,int size) {
  while (size--) {
    if (*c > 31 && *c < 127) {
      printf("%c", *c);
    }
    else {
      printf("%c", '.');
    }
    c++;
  }
  printf('\n');
}

void increment_memory(char *c) {
  int i;

  for (i = 7; i >= 0; i--) {
    if (c[i] >= 'a' && c[i] <= 'f') {
      c[i] -= 39;
    }
  }

  if ((*(c + 7) + 10) > '?') {
    *(c + 7) -= 6;
    ripple((c + 6));
  }
  else {
    *(c + 7) += 10;
  }
  for (i = 0; i < 8; i++) {
    if (*c > '9') {
      *c += 39;
    }
    c++;
  }
}

void ripple(char *c) {
  if ((*c + 1) > '?') {
    *c = '0';
    ripple(&(c[-1]));
  }
  else {
    (*c)++;
  }
}





/*int print_char(char c);

void print_string(char *str) {
  while (*str) {
    print_char(*str++);
  }
}
*/
