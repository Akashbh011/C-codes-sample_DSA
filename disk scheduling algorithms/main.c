
#include <stdio.h>
#include <stdlib.h>

#include<limits.h>

int main()
{


   /* //FCFS ALGORITHM------>>>>>
    int n,h;
    int arr[n];
    int arr1[n];
    int count=0;
    printf("enter the number of tracks :");
    scanf("%d",&n);
    printf("enter the head :");
    scanf("%d",&h);

    printf("enter the entries one by one :");

    for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
    }
    int m=h;
    for(int i=0;i<n;i++){

        m= abs(m-arr[i]);
        count+=m;
        printf(" %d ",m);
        m=arr[i];


    }

    printf("\n average seek time is : %d ",count/n);
*/



    //SSTE ALGORITHM---->>>>>
    /*int n,h;

    int x;
    int count=0;
    printf("enter the number of tracks :");
    scanf("%d",&n);
    int arr[n];
    int visited[n];
    printf("enter the head :");
    scanf("%d",&h);

    printf("enter the entries one by one :");

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }


    for(int i=0; i<n; i++)
    {   int min =9999;


        for(int j=0; j<n; j++)
        {
            if(abs(h-arr[j])<min)
            {
                min=abs(h-arr[j]);

                x=j;
            }
        }


        printf("%d ",abs(h-arr[x]));
        count+=abs(h-arr[x]);
        h=arr[x];
        arr[x]=100000;

    }
    printf("\n average seek time is : %d ",count/n);*/

    //SCAN ALGORITHM------>>>>>>>
   /* int n,h;

    int x;
    int count=0;
    printf("enter the number of tracks :");
    scanf("%d",&n);
    int arr[n];
    int visited[n];
    printf("enter the head :");
    scanf("%d",&h);

    printf("enter the entries one by one :");

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

void selectionSort(int *A, int n){
    int indexOfMin, temp;

    for (int i = 0; i < n-1; i++)
    {
        indexOfMin = i;
        for (int j = i+1; j < n; j++)
        {
            if(A[j] < A[indexOfMin]){
                indexOfMin = j;
            }
        }
        // Swap A[i] and A[indexOfMin]
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        if(arr[i]>h){
            x=i;
            break;
            }
        }


        for(int i=x; i<n; i++)
        {
            printf("%d ",abs(arr[i]-h));

            count+=abs(arr[i]-h);
            h=arr[i];
        }



     for(int i=(x-1);i>=0;i--){
        printf("%d ",abs(arr[i]-h));
        count+=abs(arr[i]-h);
        h=arr[i];
     }


     printf("\n average seek time is : %d ",count/n);
*/
//CSCAN ALGORITHM----->>>>>

int n,h;

    int x;
    int count=0;
    printf("enter the number of tracks :");
    scanf("%d",&n);
    int arr[n];
    int visited[n];
    printf("enter the head :");
    scanf("%d",&h);

    printf("enter the entries one by one :");

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

void selectionSort(int *A, int n){
    int indexOfMin, temp;

    for (int i = 0; i < n-1; i++)
    {
        indexOfMin = i;
        for (int j = i+1; j < n; j++)
        {
            if(A[j] < A[indexOfMin]){
                indexOfMin = j;
            }
        }
        // Swap A[i] and A[indexOfMin]
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        if(arr[i]>h){
            x=i;
            break;
            }
        }


        for(int i=x; i<n; i++)
        {
            printf("%d ",abs(arr[i]-h));

            count+=abs(arr[i]-h);
            h=arr[i];
        }

     for(int i=0;i<x;i++){
        printf("%d ",abs(arr[i]-h));
        count+=abs(arr[i]-h);
        h=arr[i];
     }
printf("\n average seek time is : %d ",count/n);




    return 0;
}

