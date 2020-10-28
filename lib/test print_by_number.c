#include <stdio.h>
char name[][256] = {"A太郎", "B子", "Ｃ之介"};
int student_number;
char print_by_number(int student_number, char name[][256]) {
    printf("%s", name[student_number-1]);
    return 0;
}
int main(void){
    printf("出席番号を入力してください。\n");
    scanf("%d", &student_number);
    print_by_number(student_number,name);
    return 0;
}