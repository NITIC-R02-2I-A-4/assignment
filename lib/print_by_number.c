#include  <stdio.h>
#include "macros.h"
int print_by_number(int x, char name[][MAX_STR_SIZE]);
int print_by_number(int student_number, char name [][MAX_STR_SIZE])
{
    printf("%s", name[student_number-1]);
    return 0;
} 





