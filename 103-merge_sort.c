#include "sort.h"
/**
 * merge - merge sub arrays
 * @temp: temp array to store the sorted arrays
 * @arr: original array
 * @mid: mid index
 * @right:  right sun list count
 * @left: left sublist count
 * Return: Null
 */
void merge(int arr[], int temp[], int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
		{
			temp[k] = arr[i];
			i++;
		}
		else
		{
			temp[k] = arr[j];
			j++;
		}
		k++;
	}

	while (i <= mid)
	{
		temp[k] = arr[i];
		i++;
		k++;
	}

	while (j <= right)
	{
		temp[k] = arr[j];
		j++;
		k++;
	}

	for (i = 0; i < k; i++)
	{
		arr[left + i] = temp[i];
	}
}

void mergeSortHelper(int arr[], int temp[], int left, int right) {
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		mergeSortHelper(arr, temp, left, mid);
		mergeSortHelper(arr, temp, mid + 1, right);

		merge(arr, temp, left, mid, right);
	}
}
/**
 * merge_sort - merge sort
 * @arr: original array
 * @size: size of the array
 * Return: NULL
 */
void merge_sort(int *arr, size_t size)
{
	int* temp = (int*)malloc(size * sizeof(int));

	mergeSortHelper(arr, temp, 0, size - 1);

	free(temp);
}
