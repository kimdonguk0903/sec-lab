#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    float score;
} Student;

Student* add_student(Student *arr, int *count, int id, const char *name, float score) {
    Student *tmp = realloc(arr, (*count + 1) * sizeof(Student));
    if (!tmp) {
        printf("realloc failed\n");
        return arr;
    }
    arr = tmp;
    arr[*count].id = id;
    strncpy(arr[*count].name, name, sizeof(arr[*count].name) - 1);
    arr[*count].name[sizeof(arr[*count].name) - 1] = '\0';
    arr[*count].score = score;

    (*count)++;
    return arr;
}

void print_students(Student *arr, int count) {
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Score: %.2f\n", arr[i].id, arr[i].name, arr[i].score);
    }
}

int main() {
    Student *students = NULL;
    int count = 0;

    students = add_student(students, &count, 1, "Alice", 88.5);
    students = add_student(students, &count, 2, "Bob", 92.0);
    students = add_student(students, &count, 3, "Charlie", 77.3);

    print_students(students, count);

    free(students);
    return 0;
}

