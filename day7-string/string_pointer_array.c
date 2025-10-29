#include <stdio.h>

int main() {
    const char *msgs[] = {
        "Hello, World!",
        "Pointer to String Example",
        "C Languge Practice",
        "End of Message"
    };

    int count = sizeof(msgs) / sizeof(msgs[0]);

    for (int i = 0; i < count; i++) {
        printf("[%d] %s (주소: %p)\n", i, msgs[i], msgs[i]);
    }

    return 0;
}
