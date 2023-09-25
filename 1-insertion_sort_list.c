#include "sort.h"

/**
 * swap_nodes - Swap 2 nodes in a listint_t doubly-linked list
 * @list: A pointer to the head of the doubly-linked list
 * @node1: A pointer to the 1st node to swap
 * @node2: A pointer to the second node to swap
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
 * insertion_sort_list - sorts a doubly-linked list of ints in
 * ascending order
 * @list: A pointer to the head of the doubly-linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		while (temp != NULL && temp->prev != NULL && temp->n < temp->prev->n)
		{
			swap_nodes(list, temp->prev, temp);
			print_list((const listint_t *)*list);
		}
	}
}
