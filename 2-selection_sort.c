#include "sort.h"

/**
 * selection_sort - selction sorting
 * @array: array
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	int i, j;
	int aLength = size;
	int jMin;

	/* advance the position through the entire array */
	/*   (could do i < aLength-1 because single element is also min element) */
	for (i = 0; i < aLength-1; i++)
	{
		/* find the min element in the unsorted a[i .. aLength-1] */

		/* assume the min is the first element */
		jMin = i;
		/* test against elements after i to find the smallest */
		for (j = i+1; j < aLength; j++)
		{
			/* if this element is less, then it is the new minimum */
			if (array[j] < array[jMin])
			{
				/* found new minimum; remember its index */
				jMin = j;
			}
		}

		if (jMin != i) 
		{
			swap_func(array, i, jMin);
		}
	}


}
