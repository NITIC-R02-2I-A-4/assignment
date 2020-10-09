#include <stdio.h>

#include "lib/csvloader/csvloader.h"

int main() {
	User *user;
	int result;
	result = loaduser("list.csv", user);
	if(result < 0) {
		printf("Loaduser function returned an negative value (means failed to load file)!\n");
		return 1;
	}
	printf("Loaduser has loaded %d user(s).\n", result);
	for(int i = 0;i<result;i++){
		printf("%2d: #%2d, %s (from %s)\n", i, user[i].number, user[i].name, user[i].school);
	}
	return 0;
}
