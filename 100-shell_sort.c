#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shell_sort(int *array, size_t size) {
    // Generate the Knuth sequence for intervals
    int interval = 1;
    while (interval <= size / 3) {
        interval = interval * 3 + 1;
    }

    while (interval > 0) {
        // Perform insertion sort with the current interval
        for (size_t i = interval; i < size; i++) {
            int temp = array[i];
            int j = i;

            while (j >= interval && array[j - interval] > temp) {
                array[j] = array[j - interval];
                j -= interval;
            }

            array[j] = temp;
        }

        // Print the array at each interval step
        printf("Array after interval %d: ", interval);
        for (size_t i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");

        // Update the interval using the Knuth sequence
        interval = (interval - 1) / 3;
    }
}


    }
    printf("\n");

    return 0;
}
