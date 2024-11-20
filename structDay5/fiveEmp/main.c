#include <stdio.h>
#include <windows.h>

#define EMPLOYEE_COUNT 2

struct Employee {
    int code;
    char name[50];
    int age;
    float salary;
    float bonus;
    float tax;
};

// Function to move the cursor to a specific position on the console
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;//column
    coord.Y = y;//line
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    struct Employee employees[EMPLOYEE_COUNT];

    for (int i = 0; i < EMPLOYEE_COUNT; i++) {
        // Clear the console for each employee entry
        system("cls");

        // Display form for current employee
        gotoxy(0, 0); printf("Employee %d\n", i + 1);
        gotoxy(0, 1); printf("Code:           Name:");
        gotoxy(0, 2); printf("Age:            Salary:");
        gotoxy(0, 3); printf("Bonus:          Tax:");
        gotoxy(0, 5); printf(">> Next");

        // Input fields for current employee
        gotoxy(5, 1);scanf("%d", &employees[i].code);
        gotoxy(22, 1);scanf("%s", employees[i].name);

        gotoxy(4, 2);scanf("%d", &employees[i].age);
        gotoxy(24, 2);scanf("%f", &employees[i].salary);

        gotoxy(6, 3);scanf("%f", &employees[i].bonus);
        gotoxy(21, 3);scanf("%f", &employees[i].tax);
    }

    // Clear the screen to display the summary
    system("cls");

    // Display summary of net salaries
    printf(" Net Salaries for Every Employee :\n\n");

    for (int i = 0; i < EMPLOYEE_COUNT; i++) {
        float netSalary = employees[i].salary + employees[i].bonus - employees[i].tax;
        printf("Employee Name : %s ,Code (%d) -> have Net Salary: %.2f\n",
                    employees[i].name, employees[i].code, netSalary);
    }

    printf("\n>> Bye");

    return 0;
}
