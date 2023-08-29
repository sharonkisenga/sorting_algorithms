#include <stdio.h>
#include "sort.h"


/**
 * swap_int - values of two integers
 * @s: integer s
 * @a: integer a
 */
void swap_int(int *s, int *a)
{
	int s1;

	s1 = *s;

	*s = *a;
	*a = s1;
}

/**
 * bubble_sort - sorts an array 
 * @array: array of integers
 * @size: the number 
 */
void bubble_sort(int *array, size_t size)
{
	int swapped = 1;
	size_t o, h = size;

	while (swapped == 1)
	{
		swapped = 0;
		for (o = 1; o < h; o++)
		{
			if (array[o - 1] > array[o])
			{
				swap_int(&array[o - 1], &array[o]);
				swapped = 1;
				print_array(array, size);
			}
		}
	h--;
	}

}
