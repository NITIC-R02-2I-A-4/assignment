#include <stdio.h>
#include <string.h>

int main() {
	char name[MAX_CSV_SIZE][MAX_STR_SIZE];
	char roma[MAX_CSV_SIZE][MAX_STR_SIZE];
	char jhc[MAX_CSV_SIZE][MAX_STR_SIZE];
  int result = loadfromcsv(name, roma, jhc);



  return 0;
}
