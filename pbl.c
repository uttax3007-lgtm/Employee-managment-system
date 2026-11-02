#include <stdio.h>
#include <string.h>

#define MAX 100

struct Employee {
    char id[15], name[40], role[30];
    int age;
    float salary;
};

struct Employee emp[MAX];
int count = 0;

void inputID(char id[]) {
    printf("Employee ID: ");
    scanf("%14s", id);
}

void inputName(char name[]) {
    printf("Employee Name: ");
    scanf(" %39[^\n]", name);
}

void inputAge(int *age) {
    printf("Age: ");
    scanf("%d", age);
}

void inputSalary(float *salary) {
    printf("Salary: ");
    scanf("%f", salary);
}

void inputRole(char role[]) {
    printf("Role/Position: ");
    scanf(" %29[^\n]", role);
}

int searchID(char id[]) {
    int i;
    for(i = 0; i < count; i++)
        if(strcmp(emp[i].id, id) == 0)
            return i;
    return -1;
}

void addEmployee() {
    char id[15];
    if(count == MAX) {
        printf("\nStorage Full!");
        return;
    }
    inputID(id);
    if(searchID(id) != -1) {
        printf("\nID Already Exists!");
        return;
    }
    strcpy(emp[count].id, id);
    inputName(emp[count].name);
    inputAge(&emp[count].age);
    inputSalary(&emp[count].salary);
    inputRole(emp[count].role);
    count++;
    printf("\nEmployee Added Successfully!");
}

void searchEmployee() {
    char id[15];
    int i;
    inputID(id);
    i = searchID(id);
    if(i == -1)
        printf("\nEmployee Not Found!");
    else
        printf("\nID: %s\nName: %s\nAge: %d\nSalary: %.2f\nRole: %s",
        emp[i].id, emp[i].name, emp[i].age,
        emp[i].salary, emp[i].role);
}

void deleteEmployee() {
    char id[15];
    int i, j;
    inputID(id);
    i = searchID(id);
    if(i == -1) {
        printf("\nEmployee Not Found!");
        return;
    }
    for(j = i; j < count-1; j++)
        emp[j] = emp[j+1];
    count--;
    printf("\nEmployee Deleted Successfully!");
}

void displayEmployee() {
    int i;
    if(count == 0) {
        printf("\nNo Records Found!");
        return;
    }
    printf("\nID\tNAME\tAGE\tSALARY\tROLE\n");
    for(i = 0; i < count; i++)
        printf("%s\t%s\t%d\t%.2f\t%s\n",
        emp[i].id, emp[i].name, emp[i].age,
        emp[i].salary, emp[i].role);
}

int main() {
    int choice;
    while(1) {
        printf("\n\n================================");
        printf("\n   EMPLOYEE MANAGEMENT SYSTEM");
        printf("\n================================");
        printf("\n1. Add Employee");
        printf("\n2. Delete Employee");
        printf("\n3. Search Employee");
        printf("\n4. Display Employees");
        printf("\n5. Exit");
        printf("\nEnter Choice: ");
        if(scanf("%d", &choice) != 1) {
            printf("\nInvalid Input!");
            return 0;
        }
        switch(choice) {
            case 1: addEmployee(); break;
            case 2: deleteEmployee(); break;
            case 3: searchEmployee(); break;
            case 4: displayEmployee(); break;
            case 5: printf("\nThank You!"); return 0;
            default: printf("\nInvalid Choice!");
        }
    }
}