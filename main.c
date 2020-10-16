#include <stdio.h>
#include <string.h>

#include "lib/csvloader/csvloader.h"

int loadfromcsv(char name[][MAX_STR_SIZE], char ruby[][MAX_STR_SIZE], char jsc[][MAX_STR_SIZE]) {
	printf("Load from csv has been called.\n");
  int result;
	printf("Calling loaduser....\n");
  result = loaduser("list.csv", name, ruby, jsc);
  if(result < 0) {
    printf("Loaduser function returned an negative value (means failed to load file)!\n");
    return 0;
  }
  printf("Loaduser has loaded %d user(s).\n", result);
  return result;
}

void load(){
	printf("hennlo\n");
	char name[MAX_CSV_SIZE][MAX_STR_SIZE];
	char ruby[MAX_CSV_SIZE][MAX_STR_SIZE];
	char jsc[MAX_CSV_SIZE][MAX_STR_SIZE];
  int result = loadfromcsv(name, ruby, jsc);
  for(int i = 0;i<result;i++){
    printf(
        "%2d: #%2d, %s[%s] (from %s)\n", i,
        i + 1, name[i], ruby[i], jsc[i]
    );
  }
}

void save() {
	char name[MAX_CSV_SIZE][MAX_STR_SIZE];
	char ruby[MAX_CSV_SIZE][MAX_STR_SIZE];
	char jsc[MAX_CSV_SIZE][MAX_STR_SIZE];
  int result = loadfromcsv(name, ruby, jsc);
	printf("Writing name...\n");
	strcpy(name[result], "hoge");
	printf("Writing ruby...\n");
	strcpy(ruby[result], "huga");
	printf("Writing jsc...\n");
	strcpy(jsc[result], "ABCDE");
	printf("Saving new csv...\n");
	saveuser("list-new.csv", result + 1, name, ruby, jsc, result + 1);
}

int main() {
	printf("Program started.\n");
  load();
  save();
  return 0;
}
