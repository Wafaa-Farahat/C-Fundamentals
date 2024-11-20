


#include <stdio.h>
#include <stdlib.h>

int main()
{
    //task1
   printf("Hello world!\n");

    //task2
  int asc ;
    printf("please enter a number between 0 , 127 \n" );
    scanf ("%d" ,&asc);
    char letter = (char)asc;
    printf("the conversion of : %c \n " , &letter);



    //task3
   char le ;
    printf("please enter character \n");
    getchar();
    scanf("%c",&le);
    int asci= (int)le;
    printf("the conversion of %c is: %d \n" ,le , asci);


    //task4
 int num;
    printf("plz enter number \n :");
    scanf("%d" , &num);
    printf("Hexa : %x \n" , num);
    printf("octa : %o \n" , num);

//task5
  char chr ;
    //1
    printf(" chr by getch \n");
    chr = getch();
    printf("you entered : %c \n" ,chr);
    //2
    printf("chr by getchar \n");
    chr=getchar();
    printf("you entered : %c \n",chr);
    //3
    printf("chr by getche \n");
    chr= getche();
    printf(" you entered : %c \n",chr);
    //4
    printf("chr by getc ");
    chr = getc(stdin);
    printf(" you entered : %c \n",chr);

    // task6
int num1;
printf (" Enter a positive number: ");
scanf (" %d", &num1);
// use left shift operator to shift the bits

printf (" \n After shifting the binary bits to the left side. ");
printf (" \n The new value of the variable num = %d \n", num1 << 2);

printf (" \n After shifting the binary bits to the right side. ");
printf (" \n The new value of the variable num = %d ", num1 >> 2);

  return 0;
}
