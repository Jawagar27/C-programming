#include <math.h>
#include <stdio.h>

void insertion(int A[], int size)
{

    int i, j;
    for (i = 1; i < size; i++)
    {

        int temp = A[i]; /*store the second element in the temp variable*/
        j = i - 1;       /*this denotes the first position the 0th position thereby allows us to compare the elements perfectly as the loop increments*/

        while (j >= 0 && A[j] > temp)
        {
            /*this while loop will be entered if the j value is not less than 0 and also when the value we are about to compare is greater than the temp*/

            A[j + 1] = A[j]; /*code to swap the elements*/
            j = j - 1;
        }
        A[j + 1] = temp; /*changing the temp value to make the next comparison*/
    }
}

void print(int A[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int A[] = {10, 9, 25, 66, 87};
    int size = sizeof(A) / sizeof(A[0]);

    insertion(A, size);
    print(A, size);

    return 0;
}