#include "sort.h"

int getMax(int a[], int n);
void countingSort(int a[], int n, int place);
void radix_sort(int *array, size_t size);

int getMax(int a[], int n)
{
   int max = a[0];
   int i;

   for (i = 1; i < n; i++)
   {
      if (a[i] > max)
         max = a[i];
   }
   return (max); /* maximum element from the array*/
}

void countingSort(int a[], int n, int place)
{
  int* output = (int*)malloc((n + 1) * sizeof(int));
  int count[10] = {0};
  int i;
  int placeincrement = 0;

  /* Calculate count of elements*/
  for (i = 0; i < n; i++)
    count[(a[i] / place) % 10]++;

  /* Calculate cumulative frequency*/
  for (i = 1; i < 10; i++)
    count[i] += count[i - 1];

  /* Place the elements in sorted order*/
  for (i = n - 1; i >= 0; i--) {
    output[count[(a[i] / place) % 10] - 1] = a[i];
    count[(a[i] / place) % 10]--;
    placeincrement = 1;
  }

  for (i = 0; i < n; i++)
    a[i] = output[i];
if (placeincrement > 0)
	print_array(a, n);

  free(output);
}

void radix_sort(int *array, size_t size)
{
  /* get maximum element from array */
  int max = getMax(array, size);
  int place;

  /* Apply counting sort to sort elements based on place value*/
  for (place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}

