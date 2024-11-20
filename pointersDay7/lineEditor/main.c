#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// Key definitions
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_HOME 71
#define KEY_END 79
#define KEY_ENTER 13
#define KEY_ESCAPE 27
#define KEY_BACKSPACE 8
#define KEY_DELETE 83

// Function prototypes
void gotoxy(int x, int y);
void setColor(int textColor, int bgColor);
void drawBox(int x, int y, int width, int height);
void lineEditor(int maxLength);

int main() {
    int length;
    printf("Enter the maximum number of characters for the line editor: ");
    scanf("%d", &length);
    fflush(stdin);

    system("cls");
    lineEditor(length);

    return 0;
}

// Function to move the cursor to a specific position
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function to set text and background colors
void setColor(int textColor, int bgColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgColor << 4) | textColor);
}

// Function to draw a fixed box (line editor box)
void drawBox(int x, int y, int width, int height) {
    setColor(10, 15); // Green text on white background for the editor box
    for (int i = 0; i < height; i++) {
        gotoxy(x, y + i);
        for (int j = 0; j < width; j++) {
            printf(" "); // Draw the space-filled box
        }
    }
}

// Line editor implementation
void lineEditor(int maxLength) {
    char *line = (char *)malloc(maxLength + 1); // Dynamic memory allocation
    char *start = line;
    char *current = line;
    char *end = line;

    // Initialize the line with null characters
    for (int i = 0; i <= maxLength; i++) {
        line[i] = '\0';
    }

    int x = 10, y = 5; // Starting position of the box
    int boxWidth = maxLength + 2;
    int boxHeight = 3;

     // Print title above the box
    gotoxy(x, y - 2);
    printf("------ Line Editor ------");

    // Draw the line editor box with white background and green text
    drawBox(x, y, boxWidth, boxHeight);

    // Line editor loop
    int running = 1;
    while (running) {
        gotoxy(x + 1 + (current - start), y + 1); // Place cursor in the text area
        int key = getch();

        if (key == 0 || key == 224) { // Extended keys
            key = getch();
            switch (key) {
                case KEY_LEFT: // Move cursor left
                    if (current > start) {
                        current--;
                    }
                    break;
                case KEY_RIGHT: // Move cursor right
                    if (current < end) {
                        current++;
                    }
                    break;
                case KEY_HOME: // Move cursor to the start
                    current = start;
                    break;
                case KEY_END: // Move cursor to the end
                    current = end;
                    break;
                case KEY_DELETE: // Delete character at current position
                    if (current < end) {
                        char *temp = current;
                        while (temp < end) {
                            *temp = *(temp + 1);
                            temp++;
                        }
                        end--;
                        *end = '\0';
                        // Redraw text
                        gotoxy(x + 1, y + 1);
                        printf("%-*s", maxLength, start); // Clear previous characters
                    }
                    break;
            }
        } else if (key == KEY_ENTER || key == KEY_ESCAPE) { // Finish editing
            running = 0;
            gotoxy(0, y + boxHeight + 1); // Print the output box after the editor box
            setColor(7, 0);
            if (key == KEY_ENTER) {
                printf("You entered: %s\n", start);
            } else {
                printf("User escaped. You entered: %s\n", start);
            }
        } else if (key == KEY_BACKSPACE) { // Backspace key
            if (current > start) {
                char *temp = current - 1;
                while (temp < end) {
                    *temp = *(temp + 1);
                    temp++;
                }
                end--;
                *end = '\0';
                current--; // Move cursor back
                // Redraw text
                gotoxy(x + 1, y + 1);
                printf("%-*s", maxLength, start); // Clear previous characters
            }
        } else if (key >= 32 && key <= 126) { // Printable characters
            if (end - start < maxLength) {
                char *temp = end;
                while (temp > current) {
                    *temp = *(temp - 1);
                    temp--;
                }
                *current = key;
                current++;
                end++;
                *end = '\0';
                // Redraw text
                gotoxy(x + 1, y + 1);
                printf("%-*s", maxLength, start); // Clear previous characters
            }
        }
    }

    free(line); // Free dynamically allocated memory
    setColor(7, 0); // Reset colors to default (normal output box)
}
