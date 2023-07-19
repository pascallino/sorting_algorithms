#include "sort.h"

void merge_subarray(int *subarray, int *buffer, size_t start, size_t mid, size_t end);
void merge_sort_recursive(int *subarray, int *buffer, size_t start, size_t end);
void merge_sort(int *array, size_t size);

/**
 * merge_subarray - Sorts a subarray of integers.
 * @subarray: The subarray to sort.
 * @buffer: A buffer to store the sorted subarray.
 * @start: The starting index of the subarray.
 * @mid: The middle index of the subarray.
 * @end: The ending index of the subarray.
 */
void merge_subarray(int *subarray, int *buffer, size_t start, size_t mid, size_t end)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + start, mid - start);

	printf("[right]: ");
	print_array(subarray + mid, end - mid);

	for (i = start, j = mid; i < mid && j < end; k++)
		buffer[k] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];
	for (; i < mid; i++)
		buffer[k++] = subarray[i];
	for (; j < end; j++)
		buffer[k++] = subarray[j];
	for (i = start, k = 0; i < end; i++)
		subarray[i] = buffer[k++];

	printf("[Done]: ");
	print_array(subarray + start, end - start);
}

/**
 * merge_sort_recursive - Recursively implements the merge sort algorithm.
 * @subarray: The subarray to sort.
 * @buffer: A buffer to store the sorted subarray.
 * @start: The starting index of the subarray.
 * @end: The ending index of the subarray.
 */
void merge_sort_recursive(int *subarray, int *buffer, size_t start, size_t end)
{
	size_t mid;

	if (end - start > 1)
	{
		mid = start + (end - start) / 2;
		merge_sort_recursive(subarray, buffer, start, mid);
		merge_sort_recursive(subarray, buffer, mid, end);
		merge_subarray(subarray, buffer, start, mid, end);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the merge sort algorithm.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}
