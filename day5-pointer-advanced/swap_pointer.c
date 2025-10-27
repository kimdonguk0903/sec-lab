#include <stdio.h>

void swap_by_value(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap_by_reference(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int x = 10, y = 20;
	
	printf("Before swap_by_value: x=%d, y=%d\n", x, y);
	swap_by_value(x, y);
   	printf("After swap_by_value:  x=%d, y=%d\n\n", x, y);

   	printf("Before swap_by_reference: x=%d, y=%d\n", x, y);
    	swap_by_reference(&x, &y);
    	printf("After swap_by_reference:  x=%d, y=%d\n", x, y);

   	 return 0;
}
