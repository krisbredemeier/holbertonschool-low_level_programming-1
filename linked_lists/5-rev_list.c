#include <stdio.h>
#include <stdlib.h>
#include "list.h"	

int get_size_of_list(List *);

void rev_list(List **list) {
  List *prev   = NULL;
  List *current = *list;
  List *next;
  while (current != NULL)
    {
      next = current->next;  
      current->next = prev;   
      prev = current;
      current = next;
    }

  *list = prev;
}

int get_size_of_list(List *sPtr) {
  int i;
  
  if (sPtr == NULL) {
    return (0);
  }
  
  i = 1;
  while(sPtr->next != NULL) {
    sPtr = sPtr->next;
    i++;
  }

  return i;
}
