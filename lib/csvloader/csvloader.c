#include "csvloader.h"
#include <stdio.h>
#include <string.h>

int loaduser(const char *path, char name[][MAX_STR_SIZE], char ruby[][MAX_STR_SIZE], char jsc[][MAX_STR_SIZE]) {

	printf("Load user has been called...\n");
  // Load the file
  FILE *fp;
  fp = fopen(path, "r");

  // Check the load was successful
  if(fp == NULL) {
    // If laod was failure, put error message and return
    return -1;
  }

  // Load, parse csv, and store to user array
  int number = 0;
	char row_buffer[MAX_STR_SIZE * 4 + 3];
	printf("Loading...\n");
  while(fgets(row_buffer, MAX_CSV_SIZE, fp) != NULL){
    int student_number;
    char student_name[MAX_STR_SIZE];
    char student_school[MAX_STR_SIZE];
    char student_ruby[MAX_STR_SIZE];
    sscanf(
        row_buffer,
        "%d,%[^,],%[^,],%s",
        &student_number, student_name, student_ruby, student_school
    );
		printf("Reading:    %d\n", student_number);
		printf("      NAME: \"%s\"(%lu) -> \n", student_name, strlen(student_name));
		printf("      RUBY: \"%s\"(%lu) -> \n", student_ruby, strlen(student_ruby));
		printf("    SCHOOL: \"%s\"(%lu) -> \n", student_school, strlen(student_school));
		strcpy(name[student_number - 1], student_name);
		printf("   Name copied. (%s)\n", name[student_number - 1]);
		strcpy(ruby[student_number - 1], student_ruby);
		printf("   Ruby copied. (%s)\n", ruby[student_number - 1]);
		strcpy(jsc[student_number - 1], student_school);
		printf("   JSC copied.  (%s)\n", jsc[student_number - 1]);
		printf("%d\n", student_number);
		number++;
  }
	printf("\"%s\"\n", row_buffer);
	printf("Done!\n");

  // close file stream
  fclose(fp);

  // return users
  return number;
}

int saveuser(
		const char* path, int number,
		char name[][MAX_STR_SIZE], char ruby[][MAX_STR_SIZE], char jsc[][MAX_STR_SIZE], int size) {
  // Load the file
  FILE *fp;
  fp = fopen(path, "w");

  // Check the load was successful
  // If laod was failure, put error message and return
  if(fp == NULL) return -1;

  // Print informations to csv
  for(int i = 0;i<size;i++) {
		printf("Saving: %d\n", i);
    fprintf(
      stdout, "%d,%s,%s,%s\n",
			i, name[i], ruby[i], jsc[i]
    );
    fprintf(
      fp, "%d,%s,%s,%s\n",
			i, name[i], ruby[i], jsc[i]
    );
  }

  // close file stream
  fclose(fp);

  return 0;
}

