#include <stdio.h>
#include <stdlib.h>

void leak_memory() {
	int *data = malloc(10 * sizeof(int));
	for (int i = 0; i < 10; i++)
		data[i] = i * 10;
	printf("leak (not free)\n");
}

int main() {
	leak_memory();
	return 0;
}
