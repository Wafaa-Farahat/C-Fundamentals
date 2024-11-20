#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

// Static pointer to hold the array
static int* arr = NULL;

// Flag to check if the array is filled
static int isFilled = 0;

// Static variable to hold the sum
static int sum = 0;

void displayMenu() {
    printf("\nMenu:\n");
    printf("a. Fill Array\n");
    printf("b. Get Sum of Array\n");
    printf("c. Calculate Average\n");
    printf("d. Find Maximum Value\n");
    printf("e. Find Minimum Value\n");
    printf("f. Print Reversed Array\n");
    printf("g. Sort Array (Ascending or Descending)\n");
    printf("h. Search for a Specific Value\n");
    printf("i. Exit\n");
    printf("---------------------\n");
    printf("Enter your choice: ");
}

void fillArray() {
    if (arr == NULL) {
        arr = (int*)malloc(SIZE * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
    }

    printf("Enter %d values to fill the array:\n", SIZE);
    sum = 0; // Reset sum before filling
    for (int i = 0; i < SIZE; i++) {
        printf("Enter value for element %d: ", i + 1);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    isFilled = 1;
    printf("\nArray filled successfully!\n");
}

void getSum() {
    if (!isFilled) {
        printf("Please fill the array first!\n");
    } else {
        printf("The summation of array elements is: %d\n", sum);
    }
}

void calculateAverage() {
    if (!isFilled) {
        printf("Please fill the array first!\n");
    } else {
        printf("The average of array elements is: %.2f\n", (float)sum / SIZE);
    }
}

void findMax() {
    if (!isFilled) {
        printf("Please fill the array first!\n");
    } else {
        int max = arr[0];
        for (int i = 1; i < SIZE; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        printf("The maximum value in the array is: %d\n", max);
    }
}

void findMin() {
    if (!isFilled) {
        printf("Please fill the array first!\n");
    } else {
        int min = arr[0];
        for (int i = 1; i < SIZE; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        printf("The minimum value in the array is: %d\n", min);
    }
}

void printReversed() {
    if (!isFilled) {
        printf("Please fill the array first!\n");
    } else {
        printf("The array in reverse order is:\n");
        for (int i = SIZE - 1; i >= 0; i--) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void sortArray() {
    if (!isFilled) {
        printf("Please fill the array first!\n");
    } else {
        int sortedArray[SIZE];
        for (int i = 0; i < SIZE; i++) {
            sortedArray[i] = arr[i];
        }

        char sortOrder;
        printf("Enter 'a' for ascending or 'd' for descending sort: ");
        scanf(" %c", &sortOrder);

        for (int i = 0; i < SIZE - 1; i++) {
            int selectedIndex = i;
            for (int j = i + 1; j < SIZE; j++) {
                if ((sortOrder == 'a' && sortedArray[j] < sortedArray[selectedIndex]) ||
                    (sortOrder == 'd' && sortedArray[j] > sortedArray[selectedIndex])) {
                    selectedIndex = j;
                }
            }
            int temp = sortedArray[selectedIndex];
            sortedArray[selectedIndex] = sortedArray[i];
            sortedArray[i] = temp;
        }

        printf("The array sorted in %s order is:\n", (sortOrder == 'a') ? "ascending" : "descending");
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", sortedArray[i]);
        }
        printf("\n");
    }
}

void searchValue() {
    if (!isFilled) {
        printf("Please fill the array first!\n");
    } else {
        int key, found;
        char retry;
        do {
            found = -1;
            printf("Enter the value to search for: ");
            scanf("%d", &key);
            for (int i = 0; i < SIZE; i++) {
                if (arr[i] == key) {
                    found = i;
                    break;
                }
            }
            if (found != -1) {
                printf("The value %d is found at index %d.\n", key, found);
            } else {
                printf("The value %d was not found in the array.\n", key);
            }
            printf("Do you want to search for another value? (y/n): ");
            scanf(" %c", &retry);
        } while (retry == 'y' || retry == 'Y');
    }
}

int main() {
    char choice;

    do {
        displayMenu();
        scanf(" %c", &choice);

        switch (choice) {
            case 'a': fillArray(); break;
            case 'b': getSum(); break;
            case 'c': calculateAverage(); break;
            case 'd': findMax(); break;
            case 'e': findMin(); break;
            case 'f': printReversed(); break;
            case 'g': sortArray(); break;
            case 'h': searchValue(); break;
            case 'i': printf("Exiting the program. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n"); break;
        }
    } while (choice != 'i');

    // Free allocated memory
    if (arr != NULL) {
        free(arr);
    }

    return 0;
}
