#include <stdio.h>

int main() {
	int arr[5] = {10, 20, 30, 40, 50};
	int *p = arr;

	for (int i = 0; i < 5; i++){
		printf("arr[%d] = %d, *(p + %d) = %d, &arr[%d] = %p\n",
               i, arr[i], i, *(p + i), i, &arr[i]);
    	}
	
	return 0;
}
