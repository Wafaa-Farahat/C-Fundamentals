#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define MENU_ITEMS 3

int main() {
    const char *menu[MENU_ITEMS] = {"New", "Display", "Exit"};
    int selected = 0;
    int key;

    while (1 ) {
        system("cls");  // Clear the console

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

        key = getch();  //  key press -- 1st byte from keyboard buffer

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
                printf("Welcom! You choose New option from the Menu.\n");
            } else if (selected == 1) {
                printf("Welcom! You choose Display option from the Menu.\n");
            } else if (selected == 2) {
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







/*#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define MENU_ITEMS 3

void setTextColor(int hexColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, hexColor);
}

void showMenu(int selected);
void showMessage(const char *message);

int main() {
    int selected = 0;  // Index of the selected menu item
    int key;

    while (1) {
        system("cls");  // Clear the console
        showMenu(selected);  // Show the menu with the highlighted selection

        key = getch();  // Get a key press

        if (key == 224 || key == 0) {  // Check if key is extended (224 or 0 prefix for arrow keys)
            key = getch();  // Get the extended key code

            switch (key) {
                case 72:  // UP arrow
                    selected = (selected == 0) ? MENU_ITEMS - 1 : selected - 1;
                    break;
                case 80:  // DOWN arrow
                    selected = (selected + 1) % MENU_ITEMS;
                    break;
                case 71:  // HOME key
                    selected = 0;
                    break;
                case 79:  // END key
                    selected = MENU_ITEMS - 1;
                    break;
                default:
                    break;
            }
        } else if (key == 13) {  // Enter key
            system("cls");
            if (selected == 0) {
                showMessage("Welcom! You choose New option from the Menu.");
            } else if (selected == 1) {
                showMessage("Welcom! You choose Display option from the Menu.");
            } else if (selected == 2) {
                exit(0);
            }
        } else if (key == 27) {  // ESC key
            exit(0);
        }
    }

    return 0;
}

// Function to display the menu with color highlighting
void showMenu(int selected) {
    const char *menu[MENU_ITEMS] = {"New", "Display", "Exit"};

    printf("Menu:\n");
    for (int i = 0; i < MENU_ITEMS; i++) {
        if (i == selected) {
            setTextColor(0xF0);  // White background, black text for highlight
            printf("-> %s\n", menu[i]);  // Highlight the selected item
            setTextColor(0x07);  // Reset to default color
        } else {
            printf("   %s\n", menu[i]);
        }
    }
}

// Function to display a message and wait for a key press
void showMessage(const char *message) {
    printf("%s\n", message);
    printf("Press any key to go back to the menu...\n");
    getch();  // Wait for a key press to go back
}*/
