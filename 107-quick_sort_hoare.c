#include "sort.h"
/**
*swap - swap two elements in an array
*@x: first element
*@z: second element
*/
void swap(int *x, int *z)
{
	int swap = *x;
	*x = *z;
	*z = swap;
}
/**
*quick_sort_hoare_partition - partition the array using Hoare scheme
*@arr: the array to be sorted
*@s: size of the array
*@start: starting index
*@end: ending index
*Return: the partition index
*/
int quick_sort_hoare_partition(int *arr, size_t s, int start, int end)
{
int pivot = arr[end], idx = start - 1, index = end + 1;
	while (idx < index)
{
		do {
			idx++;
		} while (arr[idx] < pivot);
		do {
			index--;
		} while (arr[index] > pivot);
		if (idx < index)
{
			swap(&arr[idx], &arr[index]);
			print_array(arr, s);
}
}
		return (idx);
}
/**
*quick_sort_hoare_recursive - recursively sort the array
*@ar: the array to be sorted
*@s: size of the array
*@start: starting index
*@end: ending index
*/
void quick_sort_hoare_recursive(int *ar, size_t s, int start, int end)
{
int array;
	if (start < end)
{
		array = quick_sort_hoare_partition(ar, s, start, end);
		quick_sort_hoare_recursive(ar, s, start, array - 1);
		quick_sort_hoare_recursive(ar, s, array, end);
}
}
/**
*quick_sort_hoare - sorts an array of integers in ascending order
*@array: the array to be sorted
*@size: the size of the array
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_hoare_recursive(array, size, 0, size - 1);
}
