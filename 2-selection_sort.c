#include "sort.h"

/**
 * selection_sort - sorts an array 
 * @array: array of integers
 * @size: the number of element
 */
void selection_sort(int *array, size_t size)
{
	size_t h, s, atleast, dur;

	for (h = 0; h < size; h++)
	{
		atleast = h;

		for (s = h + 1; s < size; s++)
		{
			if (array[s] < array[atleast])
				atleast = s;
		}
		if (array[h] > array[atleast])
		{
			dur = array[h];
			array[h] = array[atleast];
			array[atleast] =dur;
			print_array(array, size);
		}
	}
}
