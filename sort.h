#ifndef SORT_H
#define SORT_H

#define UP_Sort 0
#define DOWN_Sort 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

/*print*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/*hoare sort*/
void quick_sort_hoare(int *array, size_t size);
int quick_sort_hoare_partition(int *arr, size_t s, int start, int end);
void quick_sort_hoare_recursive(int *ar, size_t s, int start, int end);

/*bitonic*/
void bitonic_compare(int *array, size_t i, size_t j, char choose);
void bitonic_merge(int *array, size_t size, size_t low,
size_t count, char choose);
void bitonic_sort_recursive(int *array, size_t size,
size_t low, size_t count, char choose);
void bitonic_sort(int *array, size_t size);

/*radix*/
int max_value(int *array, size_t size);
void counting_sort_radix(int *array, size_t size, int exp);
void radix_sort(int *array, size_t size);

/*heap*/
void heap_sort(int *array, size_t size);
void heapify(int *arr, size_t size, size_t idx, size_t s);

/*merge*/
void merge_sort(int *array, size_t size);
void merging(int *array, size_t size, int *left, int *right);

/*counting*/
void counting_sort(int *array, size_t size);

/*coktail*/
void cocktail_sort_list(listint_t **list);
void swap_head(listint_t **list, listint_t **tail, listint_t **check);
void swap_behind(listint_t **list, listint_t **tail, listint_t **check);

/*shell*/
void shell_sort(int *array, size_t size);

/*quic*/
void swap(int *x, int *z);
int partition(int *arr, int start, int end, size_t size);
void quick_sort_recursive(int *arr, int start, int end, size_t size);
void quick_sort(int *array, size_t size);

/*selection*/
void selection_sort(int *array, size_t size);


/*insertion*/
void insertion_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);

/*bubble*/
void bubble_sort(int *array, size_t size);

#endif
