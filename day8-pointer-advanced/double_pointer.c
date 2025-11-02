#include <stdio.h>

int main() {
    int num = 10;
    int *p = &num;
    int **pp = &p;

    printf("num = %d\n", num);
    printf("p (address of num) = %p\n", p);
    printf("pp (address of p) = %p\n", pp);

    printf("*p = %d\n", *p);
    printf("**pp = %d\n", **pp);

    **pp = 20;
    printf("After **pp = 20 → num = %d\n", num);

    return 0;
}

