#include "sort.h"

/**
 * swap - swap two element in array
 * @x: first element
 * @z: seconed element
 */
void swap(int *x, int *z)
{
	int swap = *x;

	*x = *z;
	*z = swap;
}

/**
 * partition - partion an array to sort it
 * @arr: pointer to the array
 * @start: pointer to the start of array
 * @end: pointer to the end
 * @size: the size of array
 * Return: the array divied
 */
int partition(int *arr, int start, int end, size_t size)
{
	int pivot = arr[end];
	int i = start - 1;
	int j = start;

	while (j < end)
	{
		if (arr[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&arr[i], &arr[j]);
				print_array(arr, size);
			}
		}
		j++;
	}
	swap(&arr[i + 1], &arr[end]);
	print_array(arr, size);
	return (i + 1);
}

/**
 * quick_sort_recursive - help sorting with quic sort
 * @arr: pointer to the array
 * @start: pointer to the start of array
 * @end: pointer to the end
 * @size: the size of array
 */
void quick_sort_recursive(int *arr, int start, int end, size_t size)
{
	int idx;

	if (start < end)
	{
		idx = partition(arr, start, end, size);
		quick_sort_recursive(arr, start, idx - 1, size);
		quick_sort_recursive(arr, idx + 1, end, size);
	}
}

/**
 * quick_sort - sort an elements of
 * array with Lomuto partition scheme
 * @array: pointer to the array
 * @size: the size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}
