#include <stdio.h>

void add_one(int *p, int size) {
    for (int i = 0; i < size; i++) {
        p[i] += 1;
    }
}

int main() {
    int nums[3] = {1, 2, 3};

    printf("Before add_one:\n");
    for (int i = 0; i < 3; i++)
        printf("nums[%d] = %d\n", i, nums[i]);

    add_one(nums, 3);

    printf("After add_one:\n");
    for (int i = 0; i < 3; i++)
        printf("nums[%d] = %d\n", i, nums[i]);

    return 0;
}
