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

// Function to move the cursor to a specific position on the console
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main() {
    const char *menu[MENU_ITEMS] = {"New", "Display", "Display All" ,"Exit"};
    int selected = 0;
    int key;
    struct Employee employees[EMPLOYEE_COUNT] = {0}; // Initialize all employee codes to 0
    int index = -1;

    while (1 ) {
        system("cls");
        // Display the menu
        printf("Menu:\n");
        for (int i = 0; i < MENU_ITEMS; i++) {
            if (i == selected) {
                // Highlight the selected item (White background, Black text)
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 0xF0);
                printf("-> %s\n", menu[i]);//selected item
                SetConsoleTextAttribute(hConsole, 0x07);  // Reset color to default
            } else {
                printf("   %s\n", menu[i]);//to print two other unselected items of the menu
            }
        }

        key = getch();

        if (key == 224 || key == 0) {  // key is extended 224 or 0 for arrow keys
            key = getch();  // Get the actual extended key code--> which is 2nd byte in the keyboard buffer

            if (key == 72) {  // UP arrow
                selected = (selected == 0) ? MENU_ITEMS - 1/*last item in the menu*/ : selected - 1;
            } else if (key == 80) {  // DOWN arrow
                selected = (selected + 1) %/*to make menu circular*/ MENU_ITEMS;
            }
        } else if (key == 13) {  // Enter key
            system("cls");
            if (selected == 0) {


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

            system("cls");
            printf("Employee data has been entered.\n");
            printf("Press any key to go back to the menu...\n");
            system("cls");


            } else if (selected == 1) {
                printf("Welcom! You choose Display option from the Menu.\n");
            int displayIndex;
    while (1) {
        system("cls");
        printf("Please enter an employee index (1 to %d) to display, or 0 to go back: ", EMPLOYEE_COUNT);
        scanf("%d", &displayIndex);
        getchar(); // Clear the newline character left by scanf

        if (displayIndex == 0) {
            break; // Go back to the main menu
        }

        // Check if the entered index is valid and if data exists
        if (displayIndex < 1 || displayIndex > EMPLOYEE_COUNT || employees[displayIndex - 1].code == 0) {
            printf("No data found for employee index %d.\n", displayIndex);
            printf("Press Enter to try another index...");
            getchar(); // Wait for the user to press Enter to try again
            continue;
        }

        displayIndex--; // Convert to 0-based index for array
        float netSalary = employees[displayIndex].salary + employees[displayIndex].bonus - employees[displayIndex].tax;

        // Display the employee data
        system("cls");
        printf("Employee %d Data:\n", displayIndex + 1);
        printf("Code: %d\n", employees[displayIndex].code);
        printf("Name: %s\n", employees[displayIndex].name);
        printf("Age: %d\n", employees[displayIndex].age);
        printf("Salary: %.2f\n", employees[displayIndex].salary);
        printf("Bonus: %.2f\n", employees[displayIndex].bonus);
        printf("Tax: %.2f\n", employees[displayIndex].tax);
        printf("Net Salary :%.2f\n ",netSalary );

        printf("\nPress Enter to go back to the menu...\n" );
        getchar();
        break;
    }
            }
             else if (selected == 2) {
    system("cls");
    int hasData = 0; // Flag to check if any employee data exists

    printf("All Employees Data:\n\n");

    for (int i = 0; i < EMPLOYEE_COUNT; i++) {
        if (employees[i].code != 0) { // Check if employee data has been entered
            hasData = 1; // Set the flag if data is found
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

    printf("Press Enter to go back to the menu...\n");
    getchar(); // Wait for the user to press Enter to return to the menu
    getchar(); // Clear the newline character from input buffer
}
else if (selected == 3) {
                printf("Thank u for using our program \n");
                exit(0);  // Exit the program
            }
            printf("Press any key to go back to the menu...\n");
            getch();  // Wait for a key press to return to the menu
        } else if (key == 27) {  // ESC key
            exit(0);  // Exit the program
        }
    }

    return 0;
}
