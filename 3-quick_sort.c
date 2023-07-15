#include "sort.h"
/**
 * swap_quick - swap
 * @a: first data
 * @b: second ...
 * Return: null
 */
void swap_quick(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Function to partition the array
 * and return the index of the pivot
 * @arr: array
 * @low: left partition index
 * @high: right sub array/ pertition index
 * Return: NULL
 */
int partition(int *arr, int low, int high)
{
	int pivot = arr[high]; /* Choose the last element as the pivot */
	int i = low - 1; /* Index of the smaller element*/
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap_quick(&arr[i], &arr[j]);
		}
	}
	/*Place the pivot element in its correct position*/
	swap_quick(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/**
 * quickSort_helper - Function to perform Quick Sort
 * @arr: ==
 * @low: ==
 * @high: ==
 * Return: NULL
 */
void quickSort_helper(int *arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high); /*Partition the array*/

		/* Recursively sort elements before the pivot*/
		quickSort_helper(arr, low, pi - 1);
		/*Recursively sort elements after the pivot*/
		quickSort_helper(arr, pi + 1, high);
	}
}
/**
 * quick_sort - ====
 * @array: array
 * @size: size of array
 * Return: ===
 */
void quick_sort(int *array, size_t size)
{
	if (size <= 1)
		return;
	quickSort_helper(array, 0, size - 1);

}
