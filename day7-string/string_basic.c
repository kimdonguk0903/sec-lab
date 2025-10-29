#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "Hello";
    char str2[20];

    strcpy(str2, str1); //str copy
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("Length of str1: %zu\n", strlen(str1));

    printf("\n문자 단위 접근:\n");
    for (int i = 0; i < strlen(str1); i++) {
        printf("str[%d] = %c (adress : %p) \n", i, str1[i], &str1[i]);
    }

    return 0;
}
