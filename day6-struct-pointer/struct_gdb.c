#include <stdio.h>
#include <string.h>

typedef struct {
	int id;
	char name[16];
	double salary;
} Employee;

void fill_employee(Employee *e, int id, const char *name, double salary) {
	e->id = id;
	strncpy(e->name, name, sizeof(e->name)-1);
	e->name[sizeof(e->name)-1] = '\0';
	e->salary = salary;
}

int main() {
	Employee emp;
	fill_employee(&emp, 42, "Bob", 12345.67);

	printf("Employee: id=%d, name=%s, salary=%.2f\n",
           emp.id, emp.name, emp.salary);

	return 0;
}

