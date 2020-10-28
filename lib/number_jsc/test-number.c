#include<stdio.h>
#include"macros.h"
void print_number_asc(
  char name[][MAX_STR_SIZE],
  char roma[][MAX_STR_SIZE],
  char jhc[][MAX_STR_SIZE],
  int size
);
int main(void){
    int x;
    char d[50];
    printf("puts students number:");
    scanf("%d", &x);
    char a[100][MAX_STR_SIZE], b[100][MAX_STR_SIZE], c[100][MAX_STR_SIZE];
    char jhs_name[50];
    int i, size = 256;
    for(i = 0; i < x; i++){
        printf("students name in order of attendance number:");
        scanf("%s", a[i]);
    }
    for(i = 0; i < x; i++){
         printf("students ruby in order of attendance number:");
         scanf("%s", b[i]);
    }
    for(i = 0; i < x; i++){
        printf("students jhs in order of attendance number:");
        scanf("%s", c[i]);
    }
    printf("roster in order of attendance number\n");
    print_number_asc(a, b, c, x);
    return 0;
}