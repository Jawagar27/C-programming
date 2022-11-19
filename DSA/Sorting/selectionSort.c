#include <stdio.h>

void selection(int A[], int n){

int i,j;

for ( i = 0; i < n -1; i++)
{
   int min = i;
    for ( j = i + 1; j < n; j++)
    {
       if (A[min]> A[j])
       {
       
       min = j;
       int temp = A[min];
       A[min] = A[i];
       A[i] = temp;
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
int A[] = {7,4,10,8,3,1};\
int size = sizeof(A)/ sizeof(A[0]);
selection(A, size);
print(A,size);
    return 0; 
}