#include "sort.h"
/**
*bubble_sort - using it to store an array of integers
*
*@array: pointer to the array
*
*@size: the size of array
*/
void bubble_sort(int *array, size_t size)
{
size_t idx, i;
int r, swap;
	if (array == NULL || size < 2)
		return;
	for (idx = 0; idx < size - 1; idx++)
{
		swap = 0;
		for (i = 0; i < size - idx - 1; i++)
{
			if (array[i] > array[i + 1])
{
				r = array[i];
				array[i] = array[i + 1];
				array[i + 1] = r;
				swap = 1;
				print_array(array, size);
}
}
		if (swap == 0)
		break;
}
}
