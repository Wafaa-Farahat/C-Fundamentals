#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Include this for getch()

#define MAX_LENGTH 100

int main() {
    char str[MAX_LENGTH];
    int i = 0;
    char ch;

    printf("Enter a string character by character or (press Enter to end):\n");

    while (i < MAX_LENGTH - 1) {
        ch = getch();
        if (ch == '\r') {
            printf("you end the program \n");
            break;
        }

        str[i++] = ch; // Store the character in the array
        printf("%c", ch); // Display the character
    }

    str[i] = '\0'; // Null-terminate the string

     if (i > 0) {
        printf("\nYou entered: %s\n", str);
    }


    return 0;
}

