#include <stdio.h>
#include <string.h>
#include "macros.h"

struct str_with_index {
	int i;
	char *data;
};

void rank(char data[][MAX_STR_SIZE], int rank[], int size) {
	// Prepare some variables
	struct str_with_index with_index[25] = {{0, NULL}};
	struct str_with_index *sorted_ref[25];
	struct str_with_index *temp;

	// Initialize datas
	for(int i = 0;i<size;i++) {
		with_index[i].i = i;
		with_index[i].data = data[i];
		sorted_ref[i] = &with_index[i];
	}

	// Sort
	for(int i = 0;i<size;i++) {
		for(int j = 0;j<i;j++) {
			printf("[%d/%d] %s v.s. %s\n", i, j, sorted_ref[i]->data, sorted_ref[j]->data);
			if(strcmp(sorted_ref[i]->data, sorted_ref[j]->data) < 0) {
				temp = sorted_ref[j];
				sorted_ref[j] = sorted_ref[i];
				sorted_ref[i] = temp;
			}
		}
	}
	
	// Convert to rank
	for(int i = 0;i<size;i++)
		rank[i] = sorted_ref[i]->i;
}

void sort_by_name_asc(
	char name[][MAX_STR_SIZE],
	char roma[][MAX_STR_SIZE],
	char jhc[][MAX_STR_SIZE],
	int size
) {
	int ranking[MAX_USR_LENGTH] = {999};
	rank(roma, ranking, size);
	for(int i = 0; i<size;i++) {
		printf("#%d %s(%s) (@%s)\n", ranking[i], name[i], roma[i], jhc[i]);
	}
	printf("---------------------\n");
	for(int i = 0; i<size;i++) {
		printf("#%d %s(%s) (@%s)\n", ranking[i], name[ranking[i]], roma[ranking[i]], jhc[ranking[i]]);
	}
}

/* int main() {
	char name[][MAX_STR_SIZE] = {"A太郎", "C広斗", "B篤人"};
	char roma[][MAX_STR_SIZE] = {"A taro", "C hiroto", "B Atsuto"};
	char jhc[][MAX_STR_SIZE] = {"Iroha School", "Chirinu School", "Wakayo School"};
	sort_by_name_asc(name, roma, jhc, 3);
} */
