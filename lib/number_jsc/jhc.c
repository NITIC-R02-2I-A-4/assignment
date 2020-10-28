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
    for(i = 0; i < 256; i++){
      if(strcmp(jsc_name, jhc[i]) == 0){
        printf("%s, %s, %s", name[i], roma[i], jhc[i]);
      }
    }
}
