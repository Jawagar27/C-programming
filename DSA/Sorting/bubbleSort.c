#include <stdio.h>
#include <stdlib.h>


void bubble(int A[], int n){
int i,j;
int temp;

for ( j = 0; j < n -1; j++)
{
    for ( i = 0; i < n - 1; i++)
    {
        if (A[i]> A[i +1])
        {
            temp = A[i];             /*Code to swap the elements as per their size*/
            A[i]= A[i+1];
            A[i + 1]= temp;

           
        }
   }
}

}

void print(int A[], int n){
int i;

for ( i = 0; i < n; i++)
{
    printf("%d ", A[i]);
}
printf("\n");

}

int main(){

    int A[] = {10,12,1,3,25,28};
    int size = sizeof(A)/ sizeof(A[0]);
    bubble(A,size);
    print(A, size);

      return 0;
}

