#include <stdio.h>

typedef struct {
    char name[32];
    int age;
} Student;

int main() {
    FILE *fp = fopen("names.txt", "r");
    if (!fp) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    Student students[10];
    int count = 0;

    while (fscanf(fp, "%31s %d", students[count].name, &students[count].age) != EOF) {
        count++;
    }
    fclose(fp);

    printf("=== 파일에서 읽은 학생 목록 ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d) 이름: %s, 나이: %d\n", i + 1, students[i].name, students[i].age);
    }

    return 0;
}
