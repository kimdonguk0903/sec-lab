#include <stdio.h>

int main() {
	int num = 10;
	int *p = &num;

	printf("num = %d\n", num);
	printf("p = %p\n", p);
	printf("*p = %d\n", *p);

	*p = 20;
	printf("num (after *p = 20) = %d\n", num);

	return 0;
}
