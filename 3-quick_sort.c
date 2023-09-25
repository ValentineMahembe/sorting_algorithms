#include "sort.h"

/**
 * partition - order a section of the array of integers as per the
 * lomuto partition scheme with last element as the pivot
 * @array: array being sorted
 * @low: Array position 1
 * @high: array position 2
 * @size: size of te array
 *
 * Return: Final partition index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = (low - 1);

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	if (i + 1 != high)
		print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort_helper - quicksort implementation through recursion
 * @array: array being sorted
 * @low: array position 1
 * @high: array position 2
 * @size: array size
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(array, low, high, size);

		quick_sort_helper(array, low, pi - 1, size);
		quick_sort_helper(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sort an array of integers in ascending order using
 * the quicksort algorithm
 * @array: Array of integers to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}
