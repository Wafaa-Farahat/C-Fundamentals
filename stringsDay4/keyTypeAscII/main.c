#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


int main()
{


    char ch ;
    printf("Plz press any key \n");
    ch= getch();
    if(ch==-32){
            ch=getch();
        printf("u entered Extended Key ASCII --> %d", ch , ch);
    } else
    printf("u entered %c which is Normal ASCII --> %d", ch , ch);

}
