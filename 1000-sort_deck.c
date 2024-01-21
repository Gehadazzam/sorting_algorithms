#include "deck.h"

/**
*_strcmp - a function that compares two strings
*@s1: string 1 input to compare
*@s2: against this other string 2
*Return: 0 / postive / negative
*/
int _strcmp(const char *s1, const char *s2)
{
int a;

	for (a = 0; s1[a] != '\0' && s2[a] != '\0'; a++)
{
		if (s1[a] != s2[a])
{
			return (s1[a] - s2[a]);
}
}
	return (0);
}

/**
*card_value_index - Returns the index of the card value for sorting
*@value: Value of the card
*Return: Index representing the card value
*/
int card_value_index(deck_node_t *value)
{
static const char *const order[] = {"Ace", "2", "3", "4", "5", "6",
"7", "8", "9", "10", "Jack", "Queen", "King"};
int i = 0;

	while (i <= 13)
{
		if (_strcmp(value->card->value, order[i]) == 0)
			return (i);
		++i;
}
	return (-1);
}

/**
*insertion_sort_deck - Sort a deck of cards from spades to diamonds,
*and within the same kind from ace to king
*@deck: A pointer to the head of a deck_node_t doubly-linked list
*/
void insertion_sort_deck(deck_node_t **deck)
{
deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL &&
		((insert->card->kind > iter->card->kind) ||
		(insert->card->kind == iter->card->kind &&
		card_value_index(insert) > card_value_index(iter))))
{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
}
}
}

/**
*sort_deck - function that sorts a deck of cards
*@deck: doubly linked t be checked
*/
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL)
		return;
	insertion_sort_deck(deck);
}
