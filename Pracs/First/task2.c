#include <stdlib.h>
#include <stdio.h>
int factorial(int n);

int main(){

int num;

int answer; 

do
{
  
printf("Enter an integer \n");

scanf("%d", &num);

int val = num;

if (val<0)
{
    /* code */

    printf("Factorial not found for negative numbers!\n");

    break;
}


factorial(val);



  /* code */
} while ( num >= 0);

    return 0; 

}

int factorial(int n){//function to bring in the factorial part of the program. 



    int i; 
    unsigned long long fac = 1; //data type is set as an unsigned long long variable as the value could be very long int does not work here provides a resutl of 0

    for ( i = 1; i <= n; ++i)
    {
        /* code */

        fac *= i;

    }
    
    printf("Factorial is %llu", fac);
    
    return 0; 
}