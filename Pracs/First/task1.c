#include <stdlib.h>
#include <stdio.h>
int num(int x, int y);

int main(){

int num1; 
int num2; 

printf("Enter 2 integers: \n");

scanf("%d %d", &num1, &num2);

num(num1, num2);
    return 0; 
}

int num(int x, int y){

if (x%y == 0)
{
    /* code */

    printf("Divisible");
}else
{
    /* code */

        printf("Not Divisible");

}

return 0; 

}