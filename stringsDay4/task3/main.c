#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char names[3][40];
    for (int i = 0; i < 3; i++) {
        char fName[20], lName[20], fullName[40];
        printf("Please enter the first name of person %d:\n", i + 1);
        gets(fName);
        printf("Please enter the last name of person %d:\n", i + 1);
        gets(lName);
        // Concatenate
        strcpy(fullName, fName);
        strcat(fullName, " ");
        strcat(fullName, lName);

        // Store names in  array
        strcpy(names[i], fullName);
    }

    // Display all full names entered
    printf("\nThe full names you entered are:\n");
    // to loop over array indexes
    for (int i = 0; i < 3; i++) {
        puts(names[i]);
    }

    return 0;
}
