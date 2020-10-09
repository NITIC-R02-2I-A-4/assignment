#include <stdio.h>

#include "lib/csvloader/csvloader.h"

int main() {
	User *user;
	int result;
	result = loaduser("list.csv", user);
	if(result < 0) {
		printf("Loaduser function returned an negative value (means failed to load file)!\n");
	} else {
		printf("Loaduser has loaded %d user(s).\n", result);
	}
	return 0;
}
