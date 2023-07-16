#include <stdio.h>
#include <stdlib.h>

#define RANGE 255

/* The main function that sorts the given integer array arr[] in*/
/* ascending order*/
void countSort(int arr[], int size)
{
    // The output integer array that will have the sorted elements
    int output[size];

    /* Create a count array to store the count of individual*/
    /* elements and initialize count array as 0*/
    int count[RANGE + 1] = {0};

    /* Store count of each element*/
    for (int i = 0; i < size; ++i)
        ++count[arr[i]];

    /* Change count[i] so that count[i] now contains the actual*/
    /* position of this element in the output array*/
    for (int i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];

    /* Build the output array
    for (int i = size - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    /* Copy the output array to arr, so that arr now contains*/
    /* the sorted elements*/
    for (int i = 0; i < size; ++i)
        arr[i] = output[i];
}

/* Driver code*/
int main()
{
    int arr[] = {7, 3, 2, 6, 7, 1, 2, 4, 5, 3, 1, 8, 9, 4, 3, 6};

    int size = sizeof(arr) / sizeof(arr[0]);

    /* Function call*/
    countSort(arr, size);

    printf("Sorted array is: ");
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);

    return 0;
}
