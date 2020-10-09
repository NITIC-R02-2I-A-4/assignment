#include <stdio.h>
#include <string.h>

#include "lib/csvloader/csvloader.h"

int loadfromcsv(UserList *dest) {
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
  UserList user = {};
  int result = loadfromcsv(&user);
  for(int i = 0;i<result;i++){
    printf(
        "%2d: #%2d, %s[%s] (from %s)\n", i,
        user.users[i].number, user.users[i].name,
        user.users[i].ruby, user.users[i].school
    );
  }
}

void save() {
  UserList user = {};
  int result = loadfromcsv(&user);
  user.number = 4;
  user.users[3].number = 4;
  strcpy(user.users[3].name, "D次郎");
  strcpy(user.users[3].ruby, "ディージロウ");
  strcpy(user.users[3].school, "G中学");
  saveuser("list-update.csv", &user);
}

int main() {
  load();
  save();
  return 0;
}
