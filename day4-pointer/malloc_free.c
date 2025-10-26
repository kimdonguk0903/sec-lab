#include <stdio.h>
#include <stdlib.h>

int main() {
	int *ptr = malloc(sizeof(int));
	*ptr = 42;

	printf("adress: %p, value: %d\n", ptr, *ptr);

	free(ptr);

	printf("free after %d\n", *ptr);

	return 0;
}
