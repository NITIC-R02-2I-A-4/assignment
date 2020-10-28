#include<stdio.h>
#include<string.h>
#include "macros.h"
void print_by_jsc(
  char* jsc_name,
  char name[][MAX_STR_SIZE],
  char roma[][MAX_STR_SIZE],
  char jhc[][MAX_STR_SIZE],
  int size
) {
    int i;
    for(i = 0; i < size; i++){
      if(strcmp(jsc_name, jhc[i]) == 0){
        printf("%d, %s, %s, %s\n", i + 1, name[i], roma[i], jhc[i]);
      }
    }
}
