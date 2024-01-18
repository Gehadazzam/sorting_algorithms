#include "sort.h"
/**
*selection_sort - using it to sort an array of integers
*
*@array: pointer to the array
*
*@size: the size of array
*/
void selection_sort(int *array, size_t size)
{
size_t idx, i, min;
int r;
	if (array == NULL || size < 2)
		return;
	for (idx = 0; idx < size - 1; idx++)
{
		min = idx;
		for (i = idx + 1; i < size; i++)
{
			if (array[i] < array[min])
				min = i;
}
		if (min != idx)
{
			r = array[min];
			array[min] = array[idx];
			array[idx] = r;
			print_array(array, size);
}
}
}
