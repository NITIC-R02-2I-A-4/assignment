#include <stdio.h>
#include <string.h>
#include "macros.h"
#include "csvloader/csvloader.h"

int askyn(int default_yes) {
  while(1) {
    char userInput[MAX_STR_SIZE];
    scanf("%s", userInput);
    if(userInput[0] == 'y') return 1;
    if(userInput[0] == 'n') return 0;
    if(default_yes >= 0) return default_yes;
  }
}

int modify_csv(
  char name[][MAX_STR_SIZE],
  char roma[][MAX_STR_SIZE],
  char jhc[][MAX_STR_SIZE],
  int size
) {

  int cursor = size;
  if(cursor < 0) cursor = 0;
  printf("*** 名簿データ 変更ウィザード ***\n");
  while(1) {
    printf("入力した学生の数: %02d\n", cursor);
    printf("\n");
    if(cursor < (MAX_USR_LENGTH - 1)) {
      printf("(1)  %02d番の新しい学生情報を登録する\n", cursor + 1);
    }
    if(cursor > 0) {
      printf("(2)  %02d番の学生情報を削除する\n", cursor);
    }
    printf("(3)  指定した学生の情報を確認する\n");
    printf("\n");
    printf("(0)  CSVへ書き込んで終了する\n");

    int user_input;
    scanf("%d", &user_input);

    switch(user_input){
      case 1: {
        if(cursor >= (MAX_USR_LENGTH - 1)) {
          printf("[!] 登録できる学生情報が上限(%d人)を超えます。\n", MAX_USR_LENGTH);
          break;
        }
        char new_name[MAX_STR_SIZE], new_roma[MAX_STR_SIZE], new_jhc_name[MAX_STR_SIZE];
        printf("*** 出席番号 %02d ***\n", cursor + 1);
        printf("名前            : "); scanf("%s", new_name);
        printf("名前(ローマ記法): "); scanf("%s", new_roma);
        printf("出身中学校名    : "); scanf("%s", new_jhc_name);
        printf("上記の情報で登録します。[yN]");
        if(askyn(0)) {
          strcpy(name[cursor], new_name);
          strcpy(roma[cursor], new_roma);
          strcpy(jhc[cursor], new_jhc_name);
          cursor++;
          printf("書き込みました。\n");
        }
        break;
      }
      case 2:{
        if(cursor <= 0) {
          printf("[!] 削除できる学生情報がありません。\n");
          break;
        }
        printf("*** 出席番号 %02d ***\n", cursor);
        printf("名前            : %s\n", name[cursor - 1]);
        printf("名前(ローマ記法): %s\n", roma[cursor - 1]);
        printf("出身中学校名    : %s\n", jhc[cursor - 1]);
        printf("上記の情報を削除します。[yN]");
        if(askyn(0)) {
          cursor--;
          strcpy(name[cursor], "");
          strcpy(roma[cursor], "");
          strcpy(jhc[cursor], "");
        }
        break;
      }
      case 3: {
        int target_number = 0;
        printf("確認する学生の番号: "); scanf("%d", &target_number);
        printf("名前            : %s\n", name[target_number - 1]);
        printf("名前(ローマ記法): %s\n", roma[target_number - 1]);
        printf("出身中学校名    : %s\n", jhc[target_number - 1]);
        break;
      }
      case 0: {
        saveuser("list.csv", cursor, name, roma, jhc, cursor);
        printf("[i] CSVへ情報を書き込みました。ウィザードを終了します。\n");
        return cursor + 1;
      }
    }
    printf("---------------------\n\n");
  }

}

int main() {
	char name[MAX_CSV_SIZE][MAX_STR_SIZE];
	char roma[MAX_CSV_SIZE][MAX_STR_SIZE];
	char jhc[MAX_CSV_SIZE][MAX_STR_SIZE];
  int result = loaduser("list.csv", name, roma, jhc);
  modify_csv(name, roma, jhc, result);
}
