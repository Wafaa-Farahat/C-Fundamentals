#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

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

void fillArray(int arr[], int* isFilled, int* sum) {
    printf("Enter %d values to fill the array:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Enter value for element %d: ", i + 1);
        scanf("%d", &arr[i]);
        *sum += arr[i];
    }
    *isFilled = 1;
    printf("\nArray filled successfully!\n");
}

void getSum(int isFilled, int sum) {
    if (!isFilled) {
        printf("Please fill the array first!\n");
    } else {
        printf("The summation of array elements is: %d\n", sum);
    }
}

void calculateAverage(int isFilled, int sum) {
    if (!isFilled) {
        printf("Please fill the array first!\n");
    } else {
        printf("The average of array elements is: %.2f\n", (float)sum / SIZE);
    }
}

void findMax(int isFilled, int arr[]) {
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

void findMin(int isFilled, int arr[]) {
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

void printReversed(int isFilled, int arr[]) {
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

void sortArray(int isFilled, int arr[]) {
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

void searchValue(int isFilled, int arr[]) {
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
    int arr[SIZE], isFilled = 0, sum = 0;
    char choice;

    do {
        displayMenu();
        scanf(" %c", &choice);

        switch (choice) {
            case 'a': fillArray(arr, &isFilled, &sum); break;
            case 'b': getSum(isFilled, sum); break;
            case 'c': calculateAverage(isFilled, sum); break;
            case 'd': findMax(isFilled, arr); break;
            case 'e': findMin(isFilled, arr); break;
            case 'f': printReversed(isFilled, arr); break;
            case 'g': sortArray(isFilled, arr); break;
            case 'h': searchValue(isFilled, arr); break;
            case 'i': printf("Exiting the program. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n"); break;
        }
    } while (choice != 'i');

    return 0;
}
