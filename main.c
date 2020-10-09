#include <stdio.h>

#include "lib/csvloader/csvloader.h"

int main() {

	FILE *fp = fopen("list.csv", "r");
	loaduser(fp);
	fclose(fp);
	return 0;
}
