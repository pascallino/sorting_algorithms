#include <stdio.h>

// Function to swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform the sift-down operation on a heap
void sift_down(int *array, int start, int end) {
    int root = start;

    while (2 * root + 1 <= end) {
        int child = 2 * root + 1;
        int swap_index = root;

        if (array[swap_index] < array[child])
            swap_index = child;
        if (child + 1 <= end && array[swap_index] < array[child + 1])
            swap_index = child + 1;

        if (swap_index == root)
            return;
        else {
            swap(&array[root], &array[swap_index]);
            root = swap_index;
        }
    }
}

// Function to build a max heap from an array
void build_heap(int *array, int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        sift_down(array, i, size - 1);
}

// Function to perform heap sort
void heap_sort(int *array, int size) {
    build_heap(array, size);

    for (int i = size - 1; i >= 1; i--) {
        swap(&array[0], &array[i]);
        sift_down(array, 0, i - 1);
    }
}

// Function to print an array
void print_array(int *array, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// Example usage
int main() {
    int array[] = {81, 89, 9, 11, 14, 76, 54, 22};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    print_array(array, size);

    heap_sort(array, size);

    printf("Sorted array: ");
    print_array(array, size);

    return 0;
}
