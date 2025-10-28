#include <stdio.h>

int add(int a, int b) {return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int mydiv(int a, int b) { return b==0 ? 0 : a / b; }

typedef int (*op_t)(int, int);

int apply(op_t op, int x, int y) {
    return op(x, y);
    }

int main() {
    op_t f = add;
    printf("add(4,2) = %d\n", apply(f, 4, 2));

    f = sub;
    printf("sub(4,2) = %d\n", apply(f, 4, 2));

    f = mul;
    printf("mul(4,2) = %d\n", apply(f, 4, 2));

    f = mydiv;
    printf("div(7,2) = %d\n", apply(f, 7, 2));

    return 0;
}
