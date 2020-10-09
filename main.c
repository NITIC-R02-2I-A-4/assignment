#include <stdio.h>

#include "lib/csvloader/csvloader.h"

int loadfromcsv(User *dest) {
  int result;
  result = loaduser("list.csv", dest);
  if(result < 0) {
    printf("Loaduser function returned an negative value (means failed to load file)!\n");
    return 0;
  }
  printf("Loaduser has loaded %d user(s).\n", result);
  return result;
}

void load(){
  User user[MAX_CSV_SIZE];
  int result = loadfromcsv(user);
  for(int i = 0;i<result;i++){
    printf(
        "%2d: #%2d, %s[%s] (from %s)\n", i,
        user[i].number, user[i].name, user[i].ruby, user[i].school
    );
  }
}

int main() {
  load();
  return 0;
}
