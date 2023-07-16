#include "sort.h"
void cocktail_sort_list(listint_t **list);
listint_t *swap_nodes(listint_t **list, listint_t *node1,
		listint_t *node2, int pos);
/**
 * swap_nodes - swapping nodes
 * @node1: first node
 * @node2: Second node
 * @list: list
 * @pos: pos
 * Return: Current swapped node
 */
listint_t *swap_nodes(listint_t **list, listint_t *node1,
		listint_t *node2, int pos)
{
	listint_t *first = node1;
	listint_t *second = node2;

	/*Update next and prev pointers of adjacent nodes */
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
	if (pos == 2)
		return (first);
	return (second);
	/*innernode = second;*/
}
/**
 * cocktail_sort_list - sorting
 * @list: list
 * Return: return all
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = *list;
	listint_t *end = NULL;
	listint_t *begin = NULL;

	while (swapped)
	{
		swapped = 0;
		while (start != end)/* Forward pass (bubble sort)*/
		{
			if (start->n > start->next->n)
			{
				start = swap_nodes(list, start, start->next, 1);
				swapped = 1;
				print_list(*list);
			}
			start = start->next;
			if (start->next == NULL)
				break;
		}
		if (!swapped)/* If no swaps occurred, the list is sorted*/
			break;
		swapped = 0;
		start = start->prev;/* Mark the end of the sorted portion*/
		end = start;/* Backward pass (bubble sort)*/
		while (start != begin)/* Backward pass (bubble sort)*/
		{
			if (start->n < start->prev->n)
			{
				start = swap_nodes(list, start->prev, start, 2);
				swapped = 1;
				print_list(*list);
			}
			start = start->prev;
			if (start->prev == NULL)
				break;
		}
		start = start->next;
		begin = start;
	}
}

