#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[32];
    int age;
} Student;

int main() {
    int count = 3;

    Student *students = malloc(sizeof(Student) * count);
    if (!students) {
         printf("메모리 할당 실패\n");
        return 1;
    }    

    for (int i = 0; i < count; i++) {
        snprintf(students[i].name, sizeof(students[i].name), "Student_%d", i + 1);
        students[i].age = 20 + i;
    }

    for (int i = 0; i < count; i++) {
        printf("이름: %s, 나이: %d\n", students[i].name, students[i].age);
    }

    free(students);
    return 0;
}

