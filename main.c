#include "lib/macros.h"
#include "lib/csvloader/csvloader.h"
#include <stdio.h>
#include <string.h>

// lib/number_jsc/number.c
void print_number_asc(
  char name[][MAX_STR_SIZE],
  char roma[][MAX_STR_SIZE],
  char jhc[][MAX_STR_SIZE],
  int size
);

// lib/sort_by_name_asc.c
void sort_by_name_asc(
	char name[][MAX_STR_SIZE],
	char roma[][MAX_STR_SIZE],
	char jhc[][MAX_STR_SIZE],
	int size
);

// lib/print_by_number.c
int print_by_number(int number, char name [][MAX_STR_SIZE]);

// lib/print_by_name.c
int print_by_name(int number, char* query_name,  char name[][MAX_STR_SIZE]);

// lib/number_jsc/jhc.c
void print_by_jsc(
  char* jsc_name,
  char name[][MAX_STR_SIZE],
  char roma[][MAX_STR_SIZE],
  char jhc[][MAX_STR_SIZE],
  int size
);

// lib/modify_csv.c
int modify_csv(
  char name[][MAX_STR_SIZE],
  char roma[][MAX_STR_SIZE],
  char jhc[][MAX_STR_SIZE],
  int size
);

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
	   	 "(5)　出身中学から該当人物情報\n"
		   "(6)  名簿情報を入力");
	while(select <= 6){
    scanf("%d",&select);
    if(select < 1 || select > 6){
        break;
    }
		switch(select) {
			case 1: {
				print_number_asc(name, roma, jhc, result);
				break;
			}
			case 2: {
				sort_by_name_asc(name, roma, jhc, result);
				break;
			}
			case 3: {
				int target_number = 0;
				printf("表示する学生の出席番号を入力してください。");
				scanf("%d", &target_number);
				print_by_number(target_number, name);
				break;
			}
			case 4: {
				char query_name[MAX_STR_SIZE] = "";
				printf("表示する学生の氏名を入力してください。");
				scanf("%s", query_name);
				print_by_name(result, query_name, name);
				break;
			}
			case 5: {
				char jhc_name[MAX_STR_SIZE] = "";
				printf("検索する中学校名を入力してください。");
				scanf("%s", jhc_name);
				print_by_jsc(jhc_name, name, roma, jhc, result);
				break;
			}
			case 6: {
				result = modify_csv(name, roma, jhc, result);
				break;
			}
		}
		printf("\n---------------------\n");
	}

  return 0;
}
