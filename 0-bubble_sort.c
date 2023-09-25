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
 * bubble_sort - sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_and_print(array, j, j + 1, size);
			}
		}
	}
}
