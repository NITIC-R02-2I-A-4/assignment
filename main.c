#include <stdio.h>
#include <string.h>

#include "lib/csvloader/csvloader.h"

int loadfromcsv(char name[][MAX_STR_SIZE], char roma[][MAX_STR_SIZE], char jhc[][MAX_STR_SIZE]) {
  int result;
  result = loaduser("list.csv", name, roma, jhc);
  if(result < 0) {
    printf("Loaduser function returned an negative value (means failed to load file)!\n");
    return 0;
  }
  printf("Loaduser has loaded %d user(s).\n", result);
  return result;
}

void load(){
	char name[MAX_CSV_SIZE][MAX_STR_SIZE];
	char roma[MAX_CSV_SIZE][MAX_STR_SIZE];
	char jhc[MAX_CSV_SIZE][MAX_STR_SIZE];
  int result = loadfromcsv(name, roma, jhc);
  for(int i = 0;i<result;i++){
    printf(
        "%2d: #%2d, %s[%s] (from %s)\n", i,
        i + 1, name[i], roma[i], jhc[i]
    );
  }
}

void save() {
	char name[MAX_CSV_SIZE][MAX_STR_SIZE];
	char roma[MAX_CSV_SIZE][MAX_STR_SIZE];
	char jhc[MAX_CSV_SIZE][MAX_STR_SIZE];
  int result = loadfromcsv(name, roma, jhc);
	strcpy(name[result], "hoge");
	strcpy(roma[result], "huga");
	strcpy(jhc[result], "ABCDE");
	saveuser("list-new.csv", result + 1, name, roma, jhc, result + 1);
}

int main() {
  load();
  save();
  return 0;
}
