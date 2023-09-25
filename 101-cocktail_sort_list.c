#include "sort.h"

/**
 * swap_nodes - swap nodes if they are not in ascending order
 * @list: list being swapped
 * @node1: node 1 to be swapped
 * @node2: node 2 to be swapped
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	node1->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node2->prev = node1->prev;
	node2->next = node1;
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;
	node1->prev = node2;
}

/**
 * cocktail_sort_list - implement the cosktail sort on a list
 * @list: list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr;
	int swapped;

	swapped = 1;
	if (list == NULL || *list == NULL)
		return;

	curr = *list;
	while (swapped)
	{
		swapped = 0;
		while (curr->next != NULL)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes(list, curr, curr->next);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
			else
				curr = curr->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		while (curr->prev != NULL)
		{
			if (curr->n < curr->prev->n)
			{
				swap_nodes(list, curr->prev, curr);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
			else
				curr = curr->prev;
		}
	}
}
