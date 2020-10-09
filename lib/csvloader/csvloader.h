#ifndef CSV_LOADER_HEADER
#define CSV_LOADER_HEADER

#include <stdio.h>

typedef struct {
	int number;
	char name[255];
	char school[255];
} User;

User *loaduser(char*);

#endif
