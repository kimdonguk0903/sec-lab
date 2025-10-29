#include <stdio.h>
#include <string.h>

int main() {
    char saved_pw[20] = "security";
    char input_pw[20];

    printf("비밀번호 입력: ");
    scanf("%19s", input_pw);  // %19s : 최대 19자까지만 입력받음 (버퍼오버플로 방지)

    if (strcmp(saved_pw, input_pw) == 0) {
        printf("✅ 비밀번호 일치!\n");
    } else {
        printf("❌ 비밀번호 불일치!\n");
    }

    printf("입력된 문자열 길이: %zu\n", strlen(input_pw));
    return 0;
}

