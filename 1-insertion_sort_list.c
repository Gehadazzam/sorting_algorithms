#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the doubly linked list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;
	node2->prev = node1->prev;
	node1->prev = node2;
	node1->next = node2->next;
	node2->next = node1;
}

/**
 * insertion_sort_list - a function that sorts a doubly linked
 *		list of integersin ascending order
 *			using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		temp = current->prev;
		while (temp && temp->n > current->n)
		{
			swap_nodes(list, temp, current);
			print_list((const listint_t *)*list);
			temp = current->prev;
		}
		current = current->next;
	}
}
