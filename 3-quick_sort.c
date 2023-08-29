#include "sort.h"

/**
 * swap_int - swaps the values
 * @a: integer a
 * @b: integer b
 */
void swap_int(int *a, int *b)
{
	int a1;

	a1 = *a;

	*a = *b;
	*b = a1;
}

/**
 * pivot - swaps values until all lower
 * @array: array of integers
 * @size: the number of elements
 * @begin: the lowest index 
 * @end: the highest index 
 *
 * Return: the new index
 */
size_t pivot(int *array, size_t size, size_t begin, size_t end)
{
	size_t h, sauce = begin;
	int pivot_val = array[end];

	for (h = begin; h <= end; h++)
	{
		if (array[h] < pivot_val)
		{
			if (sauce != h)
			{
				swap_int(&array[h], &array[sauce]);
				print_array(array, size);
			}
			sauce++;
		}
	}
	if (end != sauce)
	{
		swap_int(&array[end], &array[sauce]);
		print_array(array, size);
	}
	return (sauce);
}

/**
 * qs_recur - recursively call array of integers
 * @array: array of integers
 * @size: the number of elements 
 * @begin: the lowest index
 * @end: the index
 */
void qs_recur(int *array, size_t size, size_t begin, size_t end)
{
	size_t pivot_idx;

	if (begin < end)
	{
		pivot_idx = pivot(array, size, begin, end);

		if (pivot_idx > begin && pivot_idx <= end)
			qs_recur(array, size, begin, pivot_idx - 1);
		if (pivot_idx >= begin && pivot_idx < end)
			qs_recur(array, size, pivot_idx + 1, end);
	}
}

/**
 * quick_sort - sorts an array 
 * @array: array of integers
 * @size: the number 
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	qs_recur(array, size, 0, size - 1);
}
