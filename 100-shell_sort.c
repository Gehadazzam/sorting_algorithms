#include "sort.h"

/**
 * swap - Swaps two integers
 * @n: Pointer to the first integer
 * @x: Pointer to the second integer
 */
void swap(int *n, int *x)
{
	int swap;

	swap = *n;
	*n = *x;
	*x = swap;
}

/**
 * shell_sort - Sorts an array of integers using
 * the Shell sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, x;

	if (array == NULL || size < 2)
		return;
	while (gap < (size / 3))
		gap = (gap * 3 + 1);
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			x = i;
			while (x >= gap && array[x - gap] > array[x])
			{
				swap(array + x, array + (x - gap));
				x -= gap;
			}
		}
		print_array(array, size);
		gap /= 3;
	}
}
