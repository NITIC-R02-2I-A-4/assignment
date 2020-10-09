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

int loaduser(const char*, User*);
int saveuser(const char*, const User*, int size);

#endif
