#include <stdio.h>
#include <string.h>

typedef struct {
	int id;
	char name [20];
	float score;
} Student;


int main() {
	Student s1;
	s1.id = 1;
	strncpy(s1.name, "Alice", sizeof(s1.name)-1);
	s1.name[sizeof(s1.name)-1] = '\0';
	s1.score = 90.5f;

	printf("s1.id    = %d\n", s1.id);
	printf("s1.name  = %s\n", s1.name);
	printf("s1.score = %.2f\n", s1.score);
	printf("\n-- addresses --\n");
	printf("&s1       = %p\n", (void*)&s1);
	printf("&s1.id    = %p\n", (void*)&s1.id);
	printf("&s1.name  = %p\n", (void*)s1.name);
	printf("&s1.score = %p\n", (void*)&s1.score);

	Student *p = &s1;
	p->score = 95.0f;

	printf("\nAfter p->score = 95.0\n");
	printf("s1.score = %.2f\n", s1.score);

	return 0;
}
