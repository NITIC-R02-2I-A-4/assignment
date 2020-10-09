#ifndef CSV_LOADER_HEADER
#define CSV_LOADER_HEADER

#include <stdio.h>

#define MAX_USER_LENGTH 40
#define MAX_CSV_SIZE 256

typedef struct {
	int number;
	char name[MAX_CSV_SIZE];
	char school[MAX_CSV_SIZE];
} User;

int loaduser(const char*, User*);

#endif
