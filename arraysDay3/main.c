#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

int main()
{

    int arr[SIZE] , isFilled=0 , sum=0;
    char choice;

    do{
        // Display the Menu
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
        scanf(" %c", &choice);

        // handle choose options
        switch(choice){
        // validate if array is filled to do any operation
        //1
          case 'a' :
        //fill the array
          printf("Enter %d values to fill the array : \n" , SIZE);
          for(int i=0 ; i < SIZE ; i++){
            printf(" Enter value for element %d : " , i+1);
            scanf("%d",&arr[i] );
            sum+=arr[i];
          }
          isFilled=1; //check if arr filled now
          printf("\n Array filled successfully !!.\n");
          break; //break case 'a'
        //2 -- summation
          case 'b'  :
            if(!isFilled){
                printf("Please fill array first ! \n");
            }else {
            printf("The summation of array elements is : %d \n ", sum);
            }
            break;
        //3 -- Average
          case 'c' :
            if(!isFilled){
                printf("Please fill array first ! \n");
            }else {
            printf("The Average of array elements is : %.2f \n ", (float)sum/SIZE);
            }
            break;
         //4 -- max value
          case 'd':
              if(!isFilled){
                printf("Please fill array first ! \n");
            }else {
                int max =arr[0];
                for(int i=0;i<SIZE;i++){
                    if(arr[i]>max)
                        max =arr[i];
                }
                printf("The maximum value in the array is: %d\n", max);
            }
              break;
        //5 -- min value
          case 'e':
               if(!isFilled){
                printf("Please fill array first ! \n");
            }else {
                int min =arr[0];
             for(int i=0;i<SIZE;i++){
                 if(arr[i]< min)
                    min=arr[i];
                }
                printf("The minimum value in the array is: %d\n", min);
            }
              break;
        //6 -- reversed array
          case 'f':
              if(!isFilled){
                printf("Please fill array first ! \n");
              }else {
                printf("The array in reverse order is:\n");
              for(int i = SIZE-1 ; i>=0;i--){
              printf("%d ", arr[i]);
              }
                printf("\n");
              }
            break;

        //7 -- sort array
        case 'g':
    if (!isFilled) {
        printf("Please fill the array first!\n");
    } else {
        int sortedArray[SIZE];

        // Copy original array to the new array
        for (int i = 0; i < SIZE; i++) {
            sortedArray[i] = arr[i];
        }

        char sortOrder;
        printf("Enter 'a' for ascending or 'd' for descending sort: ");
        scanf(" %c", &sortOrder);

        // Simple selection sort
        for (int i = 0; i < SIZE - 1; i++) {
            int selectedIndex = i;
            for (int j = i + 1; j < SIZE; j++) {
                if ((sortOrder == 'a' && sortedArray[j] < sortedArray[selectedIndex]) ||
                    (sortOrder == 'd' && sortedArray[j] > sortedArray[selectedIndex])) {
                    selectedIndex = j;
                }
            }
            // Swap the selected element with the first unsorted element
            int temp = sortedArray[selectedIndex];
            sortedArray[selectedIndex] = sortedArray[i];
            sortedArray[i] = temp;
        }

        // Print sorted array
        printf("The array sorted in %s order is:\n", (sortOrder == 'a') ? "ascending" : "descending");
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", sortedArray[i]);
        }
        printf("\n");
       }
      break;
      //8-- Search for a Specific Value
 case 'h':
    if (!isFilled) {
        printf("Please fill the array first!\n");
    } else {
        int key, found = -1;
        char retry;

        do {
            printf("Enter the value to search for: ");
            scanf("%d", &key);

            // Search the array for the key
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

            // Ask if the user wants to search again
            printf("Do you want to search for another value? (y/n): ");
            scanf(" %c", &retry);

        } while (retry == 'y' || retry == 'Y');

        printf("Exiting search.\n");
    }
    break;
//9 -- Exit
            case 'i':
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("---------------------\n");

    }while ( choice != 'i');
    return 0;
}

