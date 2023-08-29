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
 * shell_sort - sorts an array of integers
 * @array: array of integers
 * @size: the number of integer
 */
void shell_sort(int *array, size_t size)
{

	size_t h, s, interval = 1;

	while (interval < size / 3)
	{ /* This is the Knuth Sequence */
		interval = interval * 3 + 1;
	}

	while (interval > 0 && size > 1)
	{
		for (h = interval; h < size; h++)
		{
			for (s = h;
			     s > interval - 1 && array[s - interval] > array[s];
			     s -= interval)
			{
				swap_int(&array[s], &array[s - interval]);
			}
		}
		interval--;
		interval = interval / 3;
		print_array(array, size);
	}


}
