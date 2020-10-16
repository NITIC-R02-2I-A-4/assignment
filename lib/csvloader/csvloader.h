#ifndef CSV_LOADER_HEADER
#define CSV_LOADER_HEADER

#include <stdio.h>

#define MAX_USR_LENGTH 40
#define MAX_CSV_SIZE 256
#define MAX_STR_SIZE 256

int loaduser(const char *path, char name[][MAX_STR_SIZE], char ruby[][MAX_STR_SIZE], char jsc[][MAX_STR_SIZE]);
int saveuser(
		const char* path, int number,
		char name[][MAX_STR_SIZE], char ruby[][MAX_STR_SIZE], char jsc[][MAX_STR_SIZE], int size);

#endif
