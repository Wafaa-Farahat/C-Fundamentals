#include <stdio.h>
#include <windows.h>
#define EMPLOYEE_COUNT 3

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
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    struct Employee employees[EMPLOYEE_COUNT] = {0}; // Initialize all employee codes to 0
    int index = -1;

    do {
        // Clear the console for each new employee selection
        system("cls");
        printf("Please enter an index (1 to %d) to fill in employee data, or 0 to stop: ", EMPLOYEE_COUNT);
        scanf("%d", &index);

        if (index == 0) {
            break; // Exit the loop if the user enters 0
        }

        if (index < 1 || index > EMPLOYEE_COUNT) {
            printf("Invalid index. Please enter a number between 1 and %d.\n", EMPLOYEE_COUNT);
            printf("Press Enter to continue...");
            getchar(); getchar();
            continue;
        }

        index--; // Convert to 0-based index for array

        // Check if data for this employee has already been entered
        if (employees[index].code != 0) {
            printf("\nEmployee data for index %d is already filled.\n", index + 1);
            printf("Please choose another index.\n");
            printf("Press Enter to continue...");
            getchar(); getchar();
            continue;
        }

        system("cls");
        // Display form for current employee
        gotoxy(0, 0); printf("Employee %d\n", index  + 1);
        gotoxy(0, 1); printf("Code:           Name:");
        gotoxy(0, 2); printf("Age:            Salary:");
        gotoxy(0, 3); printf("Bonus:          Tax:");
        gotoxy(0, 5); printf(">> Go back to menu");

        // Input fields for current employee
        gotoxy(5, 1);scanf("%d", &employees[index ].code);
        gotoxy(22, 1);scanf("%s", employees[index ].name);

        gotoxy(4, 2);scanf("%d", &employees[index ].age);
        gotoxy(24, 2);scanf("%f", &employees[index ].salary);

        gotoxy(6, 3);scanf("%f", &employees[index ].bonus);
        gotoxy(21, 3);scanf("%f", &employees[index ].tax);

    } while (1);

    // Clear the screen to display the summary
    system("cls");

    printf("Summary of Net Salaries for Entered Employees:\n\n");
    for (int i = 0; i < EMPLOYEE_COUNT; i++) {
        if (employees[i].code != 0) { // Check if employee data has been entered based on the code field
            float netSalary = employees[i].salary + employees[i].bonus - employees[i].tax;
            printf("%d- %s --> Net Salary: %.2f\n", i + 1, employees[i].name, netSalary);
        }
    }

    printf("\n>> Bye");

    return 0;
}
