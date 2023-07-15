#include "sort.h"

/** 
 * insertion_sort_list - insert list 
 * @list - linked list to be sorted
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *outernode, *innernode;
	listint_t *first, *second;
	
    if (*list == NULL || (*list)->next == NULL)
        return;
    
    outernode = (*list)->next;
    while (outernode != NULL)
    {
        innernode = outernode;
        while (innernode->prev != NULL && innernode->prev->n > innernode->n)
        {
            first = innernode->prev;
            second = innernode;

            /* Update next and prev pointers of adjacent nodes*/
            if (first->prev != NULL)
                first->prev->next = second;
            else
                *list = second;
            
            second->prev = first->prev;
            first->prev = second;
            first->next = second->next;
            
            if (second->next != NULL)
                second->next->prev = first;
            
            second->next = first;
            
            innernode = first;
        }
        
        outernode = outernode->next;
    }
}

