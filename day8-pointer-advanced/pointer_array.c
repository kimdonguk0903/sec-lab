#include <stdio.h>

int main() {
    const char *names[] = {"Alice", "Bob", "Charlie"};

    for (int i = 0; i < 3; i++) {
        printf("names[%d] = %s (address: %p)\n", i, names[i], names[i]);
    }

    return 0;
}

