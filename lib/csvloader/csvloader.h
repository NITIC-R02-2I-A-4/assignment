#ifndef CSV_LOADER_HEADER
#define CSV_LOADER_HEADER

#include <stdio.h>

#define MAX_USER_LENGTH
#define MAX_CSV_SIZE 256

typedef struct {
	int number;
	char name[255];
	char school[255];
} User;

int loaduser(const char*, User*);

#endif
