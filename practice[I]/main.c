#include <stdio.h>
#include <stdlib.h>


void printArray(int *A,int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d",A[i]);
    }
    printf("\n");
}

int partition(int A[],int low,int high)
{

    int pivot=A[low];
    int i=low+1;
    int j=high;
    int temp;
    do
    {

        while(pivot>=A[i])
        {
            i++;
        }
        while(pivot<A[j])
        {

            j--;
        }
        if(i<j)
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }

    }
    while(j>i);

    temp=A[low];
    A[low]=A[j];
    A[j]=temp;
    return j;

}

void quicksort(int A[],int low,int high)
{

    int partitionindx;


    if(low<high)
    {

        partitionindx=partition( A, low, high);

        quicksort( A, low, partitionindx-1);

        quicksort( A, partitionindx+1, high);
    }

}


int main()
{
    int A[]= {2,3,7,5,4};
    int n=5;
    printArray(A,n);
    quicksort(A,0,n-1);
    printArray(A,n);


    return 0;
}
