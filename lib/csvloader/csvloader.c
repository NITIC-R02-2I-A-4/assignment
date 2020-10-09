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
	
	User user[MAX_USER_LENGTH] = {};
	// [TEST] Load, and parse csv
	//        And print the information with index of the line
	char row_buffer[MAX_CSV_SIZE];
	int number = 0;
	while(fgets(row_buffer, MAX_CSV_SIZE, fp) != NULL){
		int student_number;
		char student_name[256], student_school[256];
		printf("%2d: %s", ++number, row_buffer);
		sscanf(
				row_buffer,
				"%[^,],%d,%s",
				student_name, &student_number, student_school
		);
		printf(
				"%2d: #%02d %s (from %s)\n",
				number, student_number, student_name, student_school
		);
	}

	// close file stream
	fclose(fp);

	// [TEST] return empty User struct
	dest = user;
	return number;

}

