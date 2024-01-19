#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using Counting sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, i, max;

	if (array == NULL || size < 2)
		return;
	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
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
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];
	free(count);
	free(sorted);
}
