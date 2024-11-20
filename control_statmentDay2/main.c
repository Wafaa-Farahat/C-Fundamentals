#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy1(int x, int y)
{
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{

    printf("Task 1 \n");
      int size, row, col;

    printf("Enter the size of the box (odd numbers only): ");
    scanf("%d", &size);

   if (size % 2 == 0) {
        printf("Please enter an odd number!\n");
        return 1;
    }

    row=1;
    col = (size+1) / 2;

    for (int i = 1; i <= (size * size); i++) {
        gotoxy1(col * 5, row *4);
        printf("%d", i);

        if (i % size == 0)
            row++;

        else {
            col --;
            row --;
            if (col == 0 )
                col =size;
            if(row == 0)
                row=size;
        }
    }
    printf("\n-------------------- \n");

  printf("Task 2 \n\n");
    int num ,sum=0 ;

    while (sum <= 100){

    printf("Enter Numbers : " );
    scanf("%d" , &num);
    sum +=num;

    printf("The summation of the entered numbers is : %d \n\n", sum );

    }
    printf("you can't enter other nums the summation exceed 100 \n");

    printf("-------------------- \n");

   printf("Task 3 \n");
    int drink ;
  do {
    printf("choose your favorite drink : \n");
    printf("1-coffe \n");
    printf("2-Tea \n");
    printf("3-Mangoo \n");
    scanf("%d" , &drink);
     switch (drink) {
     case 1 :
        printf("Your drink is coffe \n");
        break;
     case 2:
        printf("Your drink is Tea \n");
        break;

     case 3:
        printf("Your drink is Mangoo \n");
        break;

     default :
        printf("Drink is not in the menu .. Exiting \n");
        break;

}
printf("-------------------- \n");
}while (drink >= 1 && drink <= 3);

    return 0;
}
