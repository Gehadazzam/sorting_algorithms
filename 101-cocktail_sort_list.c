#include "sort.h"

/**
 * swap_head - Swap a node in a listint_t doubly-linked list
 * @list: A pointer to the head
 * @tail: A pointer to the tail
 * @check: A pointer to the current swapping
 */
void swap_head(listint_t **list, listint_t **tail, listint_t **check)
{
	listint_t *tmp = (*check)->next;

	if ((*check)->prev != NULL)
		(*check)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*check)->prev;
	(*check)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *check;
	else
		*tail = *check;
	(*check)->prev = tmp;
	tmp->next = *check;
	*check = tmp;
}

/**
 * swap_behind - Swap a node in a listint_t doubly-linked
 * @list: A pointer to the head
 * @tail: A pointer to the tail
 * @check: A pointer to the current swapping
 */
void swap_behind(listint_t **list, listint_t **tail, listint_t **check)
{
	listint_t *tmp = (*check)->prev;

	if ((*check)->next != NULL)
		(*check)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*check)->next;
	(*check)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *check;
	else
		*list = *check;
	(*check)->next = tmp;
	tmp->prev = *check;
	*check = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list
 * @list: A pointer to the head
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp, *check;
	bool check_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	tmp = *list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (check_not_stirred == false)
	{
		check_not_stirred = true;
		for (check = *list; check != tmp; check = check->next)
		{
			if (check->n > check->next->n)
			{
				swap_head(list, &tmp, &check);
				print_list((const listint_t *)*list);
				check_not_stirred = false;
			}
		}
		for (check = check->prev; check != *list; check = check->prev)
		{
			if (check->n < check->prev->n)
			{
				swap_behind(list, &tmp, &check);
				print_list((const listint_t *)*list);
				check_not_stirred = false;
			}
		}
	}
}
