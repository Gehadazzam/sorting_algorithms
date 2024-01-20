#include "sort.h"

int max_value(int *array, size_t size);
void counting_sort_radix(int *array, size_t size, int exp);
void radix_sort(int *array, size_t size);

/**
 * max_value - Get the maximum value in an array of integers
 * @array: An array of integers
 * @size: The size of the array
 * Return: The maximum integer in the array
 */
int max_value(int *array, size_t size)
{
	int max = array[0], i = 1;

	while (i < (int)size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}

/**
 * counting_sort_radix - Sort an array of integers using Counting sort
 * @array: An array of integers
 * @size: The size of the array
 * @exp: The exponent (power of 10)
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output, *count, i;
	const int radix = 10;

	output = malloc(sizeof(int) * size);
	count = malloc(sizeof(int) * radix);
	if (output == NULL || count == NULL)
	{
		free(output);
		free(count);
		return;
	}
	for (i = 0; i < radix; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % radix] += 1;
	for (i = 0; i < radix; i++)
		count[i] += count[i - 1];
	i = (int)size - 1;
	while (i >= 0)
	{
		output[count[(array[i] / exp) % radix] - 1] = array[i];
		count[(array[i] / exp) % radix] -= 1;
		i--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	free(output);
	free(count);
}

/**
 * radix_sort - Sort an array of integers in ascending order
 * @array: An array of integers
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;
	max = max_value(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
		print_array(array, size);
	}
}
