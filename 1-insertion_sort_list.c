#include "sort.h"

/** 
 * insertion_sort_list - insert list 
 * @list - linked list to be sorted
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;
	listint_t *inner_current = current;
	listint_t *temp;
	
    if (*list == NULL || (*list)->next == NULL)
        return;
    
    
    
    while (current != NULL)
    {
        inner_current = current;
        
        while (inner_current->prev != NULL && inner_current->prev->n > inner_current->n)
        {
            // Perform the swap between inner_current and inner_current->prev
            temp = inner_current->prev;
            
            inner_current->prev = temp->prev;
            if (temp->prev != NULL)
                temp->prev->next = inner_current;
            
            temp->next = inner_current->next;
            if (inner_current->next != NULL)
                inner_current->next->prev = temp;
            
            inner_current->next = temp;
            temp->prev = inner_current;
            
            inner_current = temp;
            
            // Update the head of the list if necessary
            if (inner_current->prev == NULL)
                *list = inner_current;
        }
        
        current = current->next;
    }
}

