#include <stdio.h>
#include <string.h>

#include "lib/csvloader/csvloader.h"

int loadfromcsv(char name[][MAX_STR_SIZE], char ruby[][MAX_STR_SIZE], char jsc[][MAX_STR_SIZE]) {
  int result;
  result = loaduser("list.csv", name, ruby, jsc);
  if(result < 0) {
    printf("Loaduser function returned an negative value (means failed to load file)!\n");
    return 0;
  }
  printf("Loaduser has loaded %d user(s).\n", result);
  return result;
}

void load(){
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
	strcpy(name[result], "hoge");
	strcpy(ruby[result], "huga");
	strcpy(jsc[result], "ABCDE");
	saveuser("list-new.csv", result + 1, name, ruby, jsc, result + 1);
}

int main() {
  load();
  save();
  return 0;
}
