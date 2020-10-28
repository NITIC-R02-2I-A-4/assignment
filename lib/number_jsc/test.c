#include<stdio.h>
#include"macros.h"
void print_by_jsc(char*jhs_name, char a[][MAX_STR_SIZE], char b[][MAX_STR_SIZE], char c[][MAX_STR_SIZE], int size);
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
    printf("jhs name research\nenter jhs name\n");
    printf("jhs name:");
    scanf("%s", jhs_name);
    printf("the result of jhs name research\n");
    print_by_jsc(jhs_name, a, b, c, x);
    return 0;
}