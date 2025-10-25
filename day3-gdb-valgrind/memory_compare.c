#include <stdio.h>
#include <stdlib.h>

int main() {
	int stack_var = 10;
	int *heap_var = malloc(sizeof(int));
	*heap_var = 20;

	printf("stack_var address: %p, value: %d\n", &stack_var, stack_var);
	printf("heap_va address: %p, value: %d\n", heap_var, *heap_var);

	free(heap_var);
	return 0;
}
