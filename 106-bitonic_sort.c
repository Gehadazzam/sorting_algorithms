#include "sort.h"

/**
 * bitonic_compare - Compare elements based on direction
 * @array: Array of integers
 * @i: Index of first element
 * @j: Index of second element
 * @choose: Up or Down
 */
void bitonic_compare(int *array, size_t i, size_t j, char choose)
{
	int temp;

	if ((choose == UP_Sort && array[i] > array[j]) ||
		(choose == DOWN_Sort && array[i] < array[j]))
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

/**
 * bitonic_merge - Merge two subarrays of a Bitonic sequence
 * @array: Array of integers
 * @size: Size of the array (must be a power of 2)
 * @low: Starting index of the subarray to be merged
 * @count: Size of the subarray to be merged
 * @choose: Up or Down
 */
void bitonic_merge(int *array, size_t size,
size_t low, size_t count, char choose)
{
	size_t k = count / 2, i;

	if (count > 1)
	{
		for (i = low; i < low + k; i++)
			bitonic_compare(array, i, i + k, choose);
		bitonic_merge(array, size, low, k, choose);
		bitonic_merge(array, size, low + k, k, choose);
	}
}

/**
 * bitonic_sort_recursive - Recursive implementation of Bitonic sort
 * @array: Array of integers
 * @size: Size of the array (must be a power of 2)
 * @low: Starting index of the subarray to be sorted
 * @count: Size of the subarray to be sorted
 * @choose: Up or Down
 */
void bitonic_sort_recursive(int *array, size_t size,
size_t low, size_t count, char choose)
{
	size_t k = count / 2;

	if (count > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n",
		count, size, (choose == UP_Sort) ? "UP" : "DOWN");
		print_array(array + low, count);

		bitonic_sort_recursive(array, size, low, k, UP_Sort);
		bitonic_sort_recursive(array, size, low + k, k, DOWN_Sort);
		bitonic_merge(array, size, low, count, choose);

		printf("Result [%lu/%lu] (%s):\n",
		count, size, (choose == UP_Sort) ? "UP" : "DOWN");
		print_array(array + low, count);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 * @array: Array of integers
 * @size: Size of the array (must be a power of 2)
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonic_sort_recursive(array, size, 0, size, UP_Sort);
}
