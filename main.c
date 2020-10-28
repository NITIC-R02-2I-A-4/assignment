#include "lib/macros.h"
#include "lib/csvloader/csvloader.h"
#include <stdio.h>
#include <string.h>

int main() {
	char name[MAX_CSV_SIZE][MAX_STR_SIZE];
	char roma[MAX_CSV_SIZE][MAX_STR_SIZE];
	char jhc[MAX_CSV_SIZE][MAX_STR_SIZE];
  int result = loaduser("list.csv", name, roma, jhc);

int select = 0;
printf("表示したい項目を選び、数字を入力してください（複数可）\n"
      "入力をやめたいときは6以上の数字を入力してください\n");
printf("(1)　出席番号順の名簿情報\n"
       "(2)　氏名順の名簿情報\n"
       "(3)　出席番号から氏名を表示\n"
       "(4)　氏名から出席番号を表示\n"
	   "(5)　出身中学から該当人物情報\n");
while(select <= 5){
    scanf("%d",&select);
    if(select < 1 || select > 5){
        break;
    }
    
}

  return 0;
}
