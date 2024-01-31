#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10
#define DELAY_MICROSECONDS 1000000

void bubbleSort(int arr[], int size)
{
    for (int i=0; i< size-1 ; i++)  // for (i=n; i>0; i--)    for(j=0; j>=n-1; j++ )
    {
        for (int j=0; j< size-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                printArray(arr,size,j,j+1);
                delay(DELAY_MICROSECONDS);
            }
        }
    }
}

void delay(int microseconds)
{
     int nanoseconds = microseconds * 100;
    for(int i=0; i< nanoseconds; i++)
    {
        //empty loop to delay stuff- one iteration 
    }
}

void swap(int *a, int *b)
{
    int temp= *a;
    *a= *b;
    *b= temp;
}

void printArray(int arr[], int size, int higlight1, int higlight2)
{
    for (int i=0; i<size; i++)
    {
        if(i==higlight1 || i==higlight2)
        {
            printf("\x1b[31m%d \x1b[0m", arr[i]);  //set red colour for elements to be highlighted
        } 
        else
        {
            printf("%d ",arr[i]);
        }
    }
    printf("\r");    //carriage return character- moves cursor back to beginning of current line- overwrites content
    fflush(stdout);  // flush the o/p to make it visible immediately(w/o buffer- usually buffer time is there for printf etc)
}


int main()
{
    srand(time(NULL));
    int arr[ARRAY_SIZE];
    for(int i=0; i<ARRAY_SIZE; i++)
    {
        arr[i] = rand() % 100; //generate random integers for the array
    }

    printf("Original array:\t");
    printArray(arr,ARRAY_SIZE,-69,-69);
    printf("\n");

    printf("Sorting steps:\n");
    bubbleSort(arr,ARRAY_SIZE);

    printf("\nSorted Array:\t");
    printArray(arr,ARRAY_SIZE,-69,-69);
    printf("\n");

    return 0;
}

