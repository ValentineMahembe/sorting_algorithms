#include "sort.h"

/**
 * swap_and_print - swap 2 array items and print the array
 * @array: Array being processed
 * @i: Array position 1
 * @j: Array position 2
 * @size: Array size
 *
 */
void swap_and_print(int *array, int i, int j, size_t size)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	print_array(array, size);
}

/**
 * selection_sort - Sort an array of integers in ascending order
 * using selection sort algorithm
 * @array: Array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		if (min_idx != i)
		{
			swap_and_print(array, i, min_idx, size);
		}
	}
}
