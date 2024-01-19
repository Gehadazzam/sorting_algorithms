#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using Counting sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, i, max;
	long unsigned int x;

	if (array == NULL || size < 2)
		return;
	max = array[0];
	for (x = 1; x < size; x++)
	{
		if (array[x] > max)
			max = array[x];
	}
	sorted = malloc(sizeof(int) * size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL || sorted == NULL)
	{
		free(count);
		free(sorted);
		return;
	}
	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (x = 0; x < size; x++)
		count[array[x]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	for (x = 0; x < size; x++)
	{
		sorted[count[array[x]] - 1] = array[x];
		count[array[x]] -= 1;
	}
	for (x = 0; x < size; x++)
		array[x] = sorted[x];
	free(count);
	free(sorted);
}
