#include <stdio.h>
#include <string.h>

struct Person {
    int age;
    char name[5];
    double score;
};

int main() {
    struct Person p;

    p.age = 25;
    strncpy(p.name, "Kim", sizeof(p.name));
    p.name[sizeof(p.name) - 1] = '\0';
    p.score = 88.5;

    printf("age=%d, name=%s, score=%.1f\n", p.age, p.name, p.score);

    return 0;
}
