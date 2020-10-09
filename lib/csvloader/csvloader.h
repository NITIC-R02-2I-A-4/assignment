#ifndef CSV_LOADER_HEADER
#define CSV_LOADER_HEADER

#include <stdio.h>

#define MAX_USR_LENGTH 40
#define MAX_CSV_SIZE 256
#define MAX_STR_SIZE 256

typedef struct {
  int number;
  char name[MAX_STR_SIZE];
  char ruby[MAX_STR_SIZE];
  char school[MAX_STR_SIZE];
} User;

typedef struct {
  User users[MAX_CSV_SIZE];
  int number;
} UserList;

int loaduser(const char*, UserList*);
int saveuser(const char*, const UserList*);
int adduser(UserList*, int, const char*, const char*, const char*);
int removeuser(UserList*, int);

#endif
