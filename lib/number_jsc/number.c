#include<stdio.h>
#include "macros.h"
void print_number_asc(
  char name[][MAX_STR_SIZE],
  char roma[][MAX_STR_SIZE],
  char jhc[][MAX_STR_SIZE],
  int size
)
{
  int i;
  for(i = 0; i >= size; ++i) {
    printf("name:%s roma:%s jhc:%s\n", name, roma, jhc);
    }
}
