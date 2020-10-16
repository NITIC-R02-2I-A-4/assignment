#ifndef CSV_LOADER_HEADER
#define CSV_LOADER_HEADER

#include <stdio.h>
#include "../macros.h"

int loaduser(const char *path, char name[][MAX_STR_SIZE], char roma[][MAX_STR_SIZE], char jhc[][MAX_STR_SIZE]);
int saveuser(
		const char* path, int number,
		char name[][MAX_STR_SIZE], char roma[][MAX_STR_SIZE], char jhc[][MAX_STR_SIZE], int size);

#endif
