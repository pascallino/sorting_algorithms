#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The main function that sorts the given integer array arr[] in*/
/* ascending order*/
int findMax(int arr[], int size) {
	int max = arr[0];  /*Assume the first element as the maximum*/

		for (int i = 1; i < size; i++) {
			if (arr[i] > max) {
				max = arr[i];  /*Update the maximum if found*/
			}
		}

	return (max);
}




void countSort(int arr[], int size)
{
	// The output integer array that will have the sorted elements
	//int output[size];
	int largenum = findMax(arr, size);
	/* Create a count array to store the count of individual*/
	/* elements and initialize count array as 0*/

	int *count = malloc(sizeof(int) *  largenum + 1);
	int *output = malloc(sizeof(int) * size);
	memset(count, 0, sizeof(count));
	/* Store count of each element*/
	for (int i = 0; i < size; ++i)
		++count[arr[i]];
	for (int i = 0; i < 100; ++i)
		printf("%d ", count[i]);
	printf("\n");
	printf("\n");

	/* Change count[i] so that count[i] now contains the actual*/
	/* position of this element in the output array*/
	for (int i = 1; i <= 100; ++i)
		count[i] += count[i - 1];
	for (int i = 0; i < 100; ++i)
		printf("%d ", count[i]);
	printf("\n");


	/* Build the output array*/
	for (int i = size - 1; i >= 0; --i) {
		output[count[arr[i]] - 1] = arr[i];
		--count[arr[i]];
	}

	/* Copy the output array to arr, so that arr now contains*/
	/* the sorted elements*/
	for (int i = 0; i < size; ++i)
		arr[i] = output[i];
	free(count);
	free(output);
}

/* Driver code*/
int main()
{
	int arr[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};

	int size = sizeof(arr) / sizeof(arr[0]);

	/* Function call*/
	countSort(arr, size);

	printf("Sorted array is: ");
	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);

	return 0;
}
