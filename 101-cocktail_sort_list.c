#include "sort.h"

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2) {
    if (node1 == node2)
        return;

    if (node1->prev != NULL)
        node1->prev->next = node2;
    if (node2->next != NULL)
        node2->next->prev = node1;

    if (node2->prev == node1) {
        node1->next = node2->next;
        node2->prev = node1->prev;
        node1->prev = node2;
        node2->next = node1;
    } else {
        listint_t *temp1 = node1->prev;
        listint_t *temp2 = node1->next;
        node1->prev = node2->prev;
        node1->next = node2->next;

        if (node1->prev != NULL)
            node1->prev->next = node1;
        if (node1->next != NULL)
            node1->next->prev = node1;

        node2->prev = temp1;
        node2->next = temp2;

        if (node2->prev != NULL)
            node2->prev->next = node2;
        if (node2->next != NULL)
            node2->next->prev = node2;

        if (*list == node1)
            *list = node2;
        else if (*list == node2)
            *list = node1;
    }
}

void cocktail_sort_list(listint_t **list) {
    int swapped = 1;
    listint_t *start = *list;
    listint_t *end = NULL;

    while (swapped) {
        swapped = 0;

        /* Forward pass (bubble sort)*/
        while (start != end) {
            if (start->n > start->next->n) {
                swap_nodes(list, start, start->next);
                swapped = 1;
            }
            start = start->next;
        }

        // If no swaps occurred, the list is sorted
        if (!swapped)
            break;

        swapped = 0;
        end = start->prev; /* Mark the end of the sorted portion*/

        /* Backward pass (bubble sort)*/
        while (start != end) {
            if (start->n < start->prev->n) {
                swap_nodes(list, start->prev, start);
                swapped = 1;
            }
            start = start->prev;
        }
    }
}

