#include "sort.h"
/**
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/**
void CocktailSort(int *array, size_t n)
{
    int start = 0;
    int end = n - 1;
    int swapped;

    do {
        swapped = 0;

        /*loop from left to right*/
        for (int i = start; i < end; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(&a[i], &a[i + 1]);
                swapped = 1;
            }
        }

        /*if nothing moved, the array is sorted*/
        if (!swapped)
            break;

        swapped = 0;

        /*move the end point back by one*/
        end--;

        /*loop from right to left*/
        for (int i = end - 1; i >= start; i--)
        {
            if (a[i] > a[i + 1])
            {
                swap(&a[i], &a[i + 1]);
                swapped = 1;
            }
        }

        /*increase the starting point*/
        start++;
    } while (swapped);
}
