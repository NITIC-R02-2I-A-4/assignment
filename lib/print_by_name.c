#include <string.h>
int print_by_name(int number char* query_name,  char name[]) {
int noa;
int student_number;
for(noa = 0; noa < number ; noa++){
if(strcmp (query_name ,name[noa])== 0){
student_number = noa + 1;
}
}
printf("%d", number);
return 0;
}