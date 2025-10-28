#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int mydiv(int a, int b) { return b==0 ? 0 : a / b; }

typedef int (*op_t)(int, int);

int main() {
    op_t ops[4] = { add, sub, mul, mydiv };
    const char *names[4] = { "add", "sub", "mul", "div" };

    int a = 20, b = 5;
    for (int i = 0; i < 4; i++) {
        printf("%s(%d,%d) = %d (func addr: %p)\n",
               names[i], a, b, ops[i](a, b), (void*)ops[i]);
    }

    return 0;
}

