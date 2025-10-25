#include <stdio.h>

void funcC(int x) {
	int c = x + 3;
	printf("in funcC: c = %d\n", c);
}

void funcB(int y) {
	int b = y + 2;
	printf("in funcB: b = %d\n", b);
	funcC(b);
}

void funcA(int z) {
	int a = z + 1;
	printf("In funcA: a = %d\n", a);
	funcB(a);
}

int main () {
	int num = 5;
	printf("in main: num = %d\n", num);
	funcA(num);
	return 0;
}
