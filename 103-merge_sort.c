#include "sort.h"
/**
*merging - megere smaller arrays
*@array: pointer to the array
*@size: the size of array
*@left: pointer to the left
*@right: pointer to the right
*/
void merging(int *array, size_t size, int *left, int *right)
{
int s_l = size / 2, s_r = size - s_l;
int x = 0, y = 0, z = 0;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, s_l);
	printf("[right]: ");
	print_array(right, s_r);
	while (x < s_l && y < s_r)
{
		if (left[x] < right[y])
			array[z++] = left[x++];
		else
			array[z++] = right[y++];
}
	while (x < s_l)
		array[z++] = left[x++];
	while (y < s_r)
		array[z++] = right[y++];
	printf("[Done]: ");
	print_array(array, size);
}
/**
*merge_sort - divide every array to sort it
*
*@array: pointer to the array
*
*@size: the size of array
*/
void merge_sort(int *array, size_t size)
{
int right_half[1044], left_half[1044];
size_t idx, half = size / 2;
	if (array == NULL || size < 2)
		return;
	for (idx = 0; idx < half; idx++)
		left_half[idx] = array[idx];
	for (idx = half; idx < size; idx++)
		right_half[idx - half] = array[idx];
	merge_sort(left_half, half);
	merge_sort(right_half, size - half);
	merging(array, size, left_half, right_half);
}
