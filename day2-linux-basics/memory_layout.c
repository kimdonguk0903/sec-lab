#include <stdio.h>
#include <stdlib.h>

int main() {
	int local = 42;
	int *heap = malloc(sizeof(int));
	*heap = 99;
	
	printf("Local variable address: %p\n", &local);
	printf("Heap variable address: %p\n", heap);

	free(heap);
	return 0;
}


