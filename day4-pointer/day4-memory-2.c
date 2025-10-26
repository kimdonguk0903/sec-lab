#include <stdio.h>
#include <stdlib.h>

void allocate_and_use() {
    int *arr = (int *)malloc(5 * sizeof(int)); // 5개의 int 공간 동적 할당

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // 메모리 사용
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // ❌ intentionally forget to free (메모리 누수 발생)
    // free(arr);  // <- 이걸 주석 처리해서 누수 상황 만들기
}

void allocate_and_free() {
    int *data = (int *)malloc(3 * sizeof(int));

    if (data == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    for (int i = 0; i < 3; i++) {
        data[i] = i + 1;
        printf("data[%d] = %d\n", i, data[i]);
    }

    // ✅ 올바른 해제
    free(data);
    printf("Memory successfully freed in allocate_and_free()\n");
}

int main() {
    printf("== Memory Leak Example ==\n");
    allocate_and_use(); // 누수 발생 함수

    printf("\n== Proper Free Example ==\n");
    allocate_and_free(); // 올바른 해제 함수

    return 0;
}
