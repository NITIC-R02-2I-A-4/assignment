#include <string.h>
#include<stdio.h>
#include"macros.h"
int print_by_name(int number, char* query_name,  char name[][MAX_STR_SIZE]) {
int noa;
int student_number;
for(noa = 0; noa < number ; noa++){
if(strcmp (query_name ,name[noa])== 0){
student_number = noa + 1;
}
}
printf("%d",student_number);
return 0;
}