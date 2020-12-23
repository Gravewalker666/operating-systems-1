#include "mymalloc.h"
#include <stdio.h>

int main () {
	int *ptr = (int*) myMalloc(10 * sizeof(int));

	for (int i = 0; i < 10; i++) {
		printf("%p \n", ptr+i);
	}

	myFree(ptr);

	return 0;
}
