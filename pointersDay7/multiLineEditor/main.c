#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_HOME 71
#define KEY_END 79
#define KEY_ENTER 13
#define KEY_ESCAPE 27
#define KEY_DELETE 83
#define KEY_BACKSPACE 8
#define KEY_UP 72
#define KEY_DOWN 80

void gotoxy(int x, int y);
void setColor(int textColor, int bgColor);
void drawBox(int x, int y, int width, int height);
void lineEditor(int maxLength, int maxLines);

int main() {
    int length, lines;
    printf("Enter the maximum number of characters per line: ");
    scanf("%d", &length);
    printf("Enter the maximum number of lines: ");
    scanf("%d", &lines);
    fflush(stdin);

    system("cls");
    lineEditor(length, lines);

    return 0;
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int textColor, int bgColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgColor << 4) | textColor);
}

void drawBox(int x, int y, int width, int height) {
    setColor(0, 15);
    for (int i = 0; i < height; i++) {
        gotoxy(x, y + i);
        for (int j = 0; j < width; j++) {
            printf(" ");
        }
    }
}

void lineEditor(int maxLength, int maxLines) {
    char *line = (char *)malloc(maxLength * maxLines + 1);
    char *start = line;
    char *end = line;
    int cursorPos = 0;
    int currentLine = 0;
    int x = 10, y = 5;

    for (int i = 0; i < maxLength * maxLines + 1; i++) {
        line[i] = '\0';
    }

    gotoxy(x, y - 2);
    printf(" ------ Multi-Line Editor ------");
    drawBox(x, y, maxLength + 2, maxLines + 2);
    setColor(10, 15);

    int running = 1;
    while (running) {
        gotoxy(x + 1 + cursorPos, y + 1 + currentLine);
        int key = getch();

        if (key == 0 || key == 224) {
            key = getch();
            switch (key) {
                case KEY_LEFT:
                    if (cursorPos > 0) {
                        cursorPos--;
                    }
                    break;

                case KEY_RIGHT:
                    if (cursorPos < maxLength - 1 && *(start + currentLine * maxLength + cursorPos) != '\0') {
                        cursorPos++;
                    } else if (currentLine < maxLines - 1) {
                        currentLine++;
                        cursorPos = 0;
                    }
                    break;

                case KEY_UP:
                    if (currentLine > 0) {
                        currentLine--;
                        if (cursorPos > maxLength || *(start + currentLine * maxLength + cursorPos) == '\0') {
                            cursorPos = 0;
                            while (*(start + currentLine * maxLength + cursorPos) != '\0') {
                                cursorPos++;
                            }
                        }
                    }
                    break;

                case KEY_DOWN:
                    if (currentLine < maxLines - 1) {
                        currentLine++;
                        if (cursorPos > maxLength || *(start + currentLine * maxLength + cursorPos) == '\0') {
                            cursorPos = 0;
                            while (*(start + currentLine * maxLength + cursorPos) != '\0') {
                                cursorPos++;
                            }
                        }
                    }
                    break;

                case KEY_HOME:
                    cursorPos = 0; // Move cursor to before the first letter
                    break;

                case KEY_END:
                    while (*(start + currentLine * maxLength + cursorPos) != '\0' && cursorPos < maxLength) {
                        cursorPos++; // Move cursor to after the last character in the line
                    }
                    break;

                case KEY_BACKSPACE:
                    if (cursorPos > 0) {
                        cursorPos--;
                        char *temp = start + currentLine * maxLength + cursorPos;
                        while (*(temp + 1) != '\0') {
                            *temp = *(temp + 1);
                            temp++;
                        }
                        *temp = '\0';
                        gotoxy(x + 1, y + 1 + currentLine);
                        printf("%-*s", maxLength, start + currentLine * maxLength);
                    }
                    break;

                case KEY_DELETE:
                    if (*(start + currentLine * maxLength + cursorPos) != '\0') {
                        char *temp = start + currentLine * maxLength + cursorPos;
                        while (*(temp + 1) != '\0') {
                            *temp = *(temp + 1);
                            temp++;
                        }
                        *temp = '\0';
                        gotoxy(x + 1, y + 1 + currentLine);
                        printf("%-*s", maxLength, start + currentLine * maxLength);
                    }
                    break;
            }
        } else if (key == KEY_ENTER) {
            if (currentLine < maxLines - 1) {
                currentLine++;
                cursorPos = 0;
            }
        } else if (key == KEY_ESCAPE) {
            running = 0;
            gotoxy(x, y + maxLines + 3);
            setColor(14, 0);
            printf("You entered:");

            for (int i = 0; i <= currentLine; i++) {
                gotoxy(x + 2, y + maxLines + 4 + i);
                printf("%s", start + i * maxLength);
            }

            gotoxy(0, y + maxLines + 6 + currentLine);
            printf("\nPress any key to exit...");
            getch();
        } else if (key >= 32 && key <= 126) {
            if (end - start < maxLength * maxLines) {
                char *temp = end;
                while (temp > start + currentLine * maxLength + cursorPos) {
                    *temp = *(temp - 1);
                    temp--;
                }
                *(start + currentLine * maxLength + cursorPos) = key;
                cursorPos++;
                end++;
                *end = '\0';
                gotoxy(x + 1, y + 1 + currentLine);
                printf("%-*s", maxLength, start + currentLine * maxLength);
            }
        }
    }

    free(line);
    setColor(7, 0);
}
