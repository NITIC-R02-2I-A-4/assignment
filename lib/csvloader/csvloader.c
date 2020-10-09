#include "csvloader.h"
#include <stdio.h>

int loaduser(const char *path, User *dest) {

	// Load the file
	FILE *fp;
	fp = fopen(path, "r");
	
	// Check the load was successful
	if(fp == NULL) {
		// If laod was failure, put error message and return
		dest = NULL;
		return -1;
	}
	
	// [TEST] Load and print the whole line of the file with index of line
	char row_buffer[MAX_CSV_SIZE];
	int number = 0;
	while(fgets(row_buffer, MAX_CSV_SIZE, fp) != NULL){
		printf("%2d: %s", ++number, row_buffer);
	}

	// close file stream
	fclose(fp);

	// [TEST] return empty User struct
	User user[MAX_USER_LENGTH] = {};
	dest = user;
	return number;

}

