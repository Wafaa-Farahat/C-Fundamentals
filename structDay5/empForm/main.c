#include <stdio.h>
#include <windows.h>

struct Employee {
    int code;
    char name[50];
    int age;
    float salary;
    float bonus;
    float tax;
};

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;//column
    coord.Y = y;//line
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    struct Employee emp;

    system("cls");

    // Display the form layout starting from the first row and first column
    gotoxy(0, 0); printf("Employee Form\n");
    gotoxy(0, 1); printf("Code:            Name:");
    gotoxy(0, 2); printf("Age:             Salary:");
    gotoxy(0, 3); printf("Bonus:           Tax:");
   // gotoxy(0, 5); printf("Press Enter after each entry...\n");

    // Position cursor for each input field

    //first line
    //----------
    // Position after "Code: "
    gotoxy(5, 1); scanf("%d", &emp.code);
    // Position after "Name: "
    gotoxy(22, 1); scanf("%s", emp.name);

    //second line
    //----------
    // Position after "Age: "
    gotoxy(4, 2); scanf("%d", &emp.age);
    // Position after "Salary: "
    gotoxy(24, 2); scanf("%f", &emp.salary);

    //third line
    //----------
     // Position after "Bonus: "
    gotoxy(6, 3);scanf("%f", &emp.bonus);
    // Position after "Tax: "
    gotoxy(21, 3);scanf("%f", &emp.tax);

    // Calculate net salary
    float netSalary = emp.salary + emp.bonus - emp.tax;

    // Clear the screen and display the result
    system("cls");
    printf("Employee name: %s , Code( %d )\n", emp.name, emp.code);
    printf("Net Salary: %.2f\n", netSalary);

    return 0;
}
