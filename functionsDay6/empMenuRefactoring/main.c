#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define MENU_ITEMS 4
#define EMPLOYEE_COUNT 3

struct Employee {
    int code;
    char name[50];
    int age;
    float salary;
    float bonus;
    float tax;
};

// Function prototypes
void gotoxy(int x, int y);
void displayMenu(const char *menu[], int selected);
int handleMenuSelection(int selected, struct Employee employees[]);
void addEmployee(struct Employee employees[]);
void displayEmployee(const struct Employee employees[]);
void displayAllEmployees(const struct Employee employees[]);

// Main function
int main() {
    const char *menu[MENU_ITEMS] = {"New", "Display", "Display All", "Exit"};
    int selected = 0;
    int key;
    struct Employee employees[EMPLOYEE_COUNT] = {0}; // Initialize all employee codes to 0

    while (1) {
        system("cls");
        displayMenu(menu, selected);

        key = getch();

        if (key == 224 || key == 0) {  // Handle arrow keys
            key = getch();
            if (key == 72) {  // UP arrow
                selected = (selected == 0) ? MENU_ITEMS - 1 : selected - 1;
            } else if (key == 80) {  // DOWN arrow
                selected = (selected + 1) % MENU_ITEMS;
            }
        } else if (key == 13) {  // Enter key
            if (!handleMenuSelection(selected, employees)) {
                break; // Exit the loop if "Exit" is selected
            }
        } else if (key == 27) {  // ESC key
            break; // Exit the program
        }
    }

    return 0;
}

// Function to move the cursor to a specific position on the console
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function to display the menu
void displayMenu(const char *menu[], int selected) {
    printf("Menu:\n");
    for (int i = 0; i < MENU_ITEMS; i++) {
        if (i == selected) {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 0xF0);
            printf("-> %s\n", menu[i]);
            SetConsoleTextAttribute(hConsole, 0x07);
        } else {
            printf("   %s\n", menu[i]);
        }
    }
}

// Function to handle menu selection
int handleMenuSelection(int selected, struct Employee employees[]) {
    system("cls");
    switch (selected) {
        case 0: // Add new employee
            addEmployee(employees);
            break;
        case 1: // Display a single employee
            displayEmployee(employees);
            break;
        case 2: // Display all employees
            displayAllEmployees(employees);
            break;
        case 3: // Exit
            printf("Thank you for using our program.\n");
            return 0;
    }
    printf("Press any key to go back to the menu...\n");
    getch();
    return 1;
}

// Function to add a new employee
void addEmployee(struct Employee employees[]) {
    int index;
    printf("Enter an index (1 to %d) to fill employee data, or 0 to stop: ", EMPLOYEE_COUNT);
    scanf("%d", &index);

    if (index == 0) return;

    if (index < 1 || index > EMPLOYEE_COUNT) {
        printf("Invalid index. Please try again.\n");
        return;
    }

    index--; // Convert to 0-based index
    system("cls");
    gotoxy(0, 0); printf("Employee %d\n", index + 1);
    gotoxy(0, 1); printf("Code:           Name:");
    gotoxy(0, 2); printf("Age:            Salary:");
    gotoxy(0, 3); printf("Bonus:          Tax:");
    gotoxy(0, 5); printf(">> Go back to menu");

    gotoxy(5, 1); scanf("%d", &employees[index].code);
    gotoxy(22, 1); scanf("%s", employees[index].name);
    gotoxy(4, 2); scanf("%d", &employees[index].age);
    gotoxy(24, 2); scanf("%f", &employees[index].salary);
    gotoxy(6, 3); scanf("%f", &employees[index].bonus);
    gotoxy(21, 3); scanf("%f", &employees[index].tax);

    printf("Employee data has been entered.\n");
}

// Function to display a single employee
void displayEmployee(const struct Employee employees[]) {
    int index;
    printf("Enter an index (1 to %d) to display employee data, or 0 to go back: ", EMPLOYEE_COUNT);
    scanf("%d", &index);

    if (index == 0) return;

    if (index < 1 || index > EMPLOYEE_COUNT || employees[index - 1].code == 0) {
        printf("Invalid index or no data available. Please try again.\n");
        return;
    }

    index--; // Convert to 0-based index
    float netSalary = employees[index].salary + employees[index].bonus - employees[index].tax;
    printf("Employee %d Data:\n", index + 1);
    printf("Code: %d\n", employees[index].code);
    printf("Name: %s\n", employees[index].name);
    printf("Age: %d\n", employees[index].age);
    printf("Salary: %.2f\n", employees[index].salary);
    printf("Bonus: %.2f\n", employees[index].bonus);
    printf("Tax: %.2f\n", employees[index].tax);
    printf("Net Salary: %.2f\n", netSalary);
}

// Function to display all employees
void displayAllEmployees(const struct Employee employees[]) {
    int hasData = 0;
    printf("All Employees Data:\n\n");

    for (int i = 0; i < EMPLOYEE_COUNT; i++) {
        if (employees[i].code != 0) {
            hasData = 1;
            float netSalary = employees[i].salary + employees[i].bonus - employees[i].tax;
            printf("Employee %d:\n", i + 1);
            printf("  Code: %d\n", employees[i].code);
            printf("  Name: %s\n", employees[i].name);
            printf("  Age: %d\n", employees[i].age);
            printf("  Salary: %.2f\n", employees[i].salary);
            printf("  Bonus: %.2f\n", employees[i].bonus);
            printf("  Tax: %.2f\n", employees[i].tax);
            printf("  Net Salary: %.2f\n\n", netSalary);
        }
    }

    if (!hasData) {
        printf("No employee data available.\n");
    }
}
