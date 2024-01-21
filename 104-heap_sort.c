#include "sort.h"
/**
*swap - Swaps two integers
*@x: Pointer to the first integer
*@z: Pointer to the second integer
*/
void swap(int *x, int *z)
{
	int swap = *x;
	*x = *z;
	*z = swap;
}
/**
*heapify - Maintains heap property at a given index
*@arr: Array to be heapified
*@size: Size of the array
*@idx: Index to start
*@s: for print
*/
void heapify(int *arr, size_t size, size_t idx, size_t s)
{
size_t largest = idx,  left = 2 * idx + 1, right = 2 * idx + 2;
	if (left < size && arr[left] > arr[largest])
		largest = left;
	if (right < size && arr[right] > arr[largest])
		largest = right;
	if (largest != idx)
{
		swap(&arr[idx], &arr[largest]);
		print_array(arr, s);
		heapify(arr, size, largest, s);
}
}
/**
*heap_sort - Sorts an array of integers in ascending order
*using the Heap sort algorithm
*@array: Array to be sorted
*@size: Size of the array
*/
void heap_sort(int *array, size_t size)
{
int idx;
	if (array == NULL || size < 2)
		return;
	for (idx = size / 2 - 1; idx >= 0; idx--)
		heapify(array, size, idx, size);
	for (idx = size - 1; idx > 0; idx--)
{
		swap(&array[0], &array[idx]);
		print_array(array, size);
		heapify(array, idx, 0, size);
}
}
