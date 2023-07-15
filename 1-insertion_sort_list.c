#include "sort.h"

/** 
 * insertion_sort_list - insert list 
 * @list - linked list to be sorted
 * Return: void
 */

/**	i ← 1
while i < length(A)
	j ← i
	while j > 0 and A[j-1] > A[j]
	swap A[j] and A[j-1]
	j ← j - 1
	end while
	i ← i + 1
	end while*/

void insertion_sort_list(listint_t **list)
{
listint_t *outernode = *list, *innernode;
listint_t *first, *second;

/**while (node != NULL)
{
	len++;
	node = node->next;
}*/
outernode = outernode->next;
while (outernode != NULL)
{
	innernode = outernode;
while (innernode != NULL and node->prev->n > node->n)
{
	first = innernode->prev;
	second = innernode;
	first->next = second->next;

	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	first->prev = second;

	innernode = innernode->prev;
}
outernode = outernode->next;
}
}
