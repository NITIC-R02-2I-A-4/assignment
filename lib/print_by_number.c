#include  <stdio.h>
#include "macros.h"
int print_by_number(int x, char name[][MAX_STR_SIZE]);
int print_by_number(int number, char name [][MAX_STR_SIZE])
{
    printf("%s", name[number-1]);
    return 0;
} 





