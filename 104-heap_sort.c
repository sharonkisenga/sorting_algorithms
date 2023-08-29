#include "sort.h"

/**
* sift_down - fixes sifs down 
* @array: array to be fixed
* @root: root array
* @end: end to sift
* @size: size array
*/
void sift_down(int *array, size_t root, size_t end, size_t size)
{
	size_t man, girl, cap;
	int bic;

	while ((man = (2 * root) + 1) <= end)
	{
		cap = root;
		girl = man + 1;
		if (array[cap] < array[man])
			cap = man;
		if (girl <= end && array[cap] < array[girl])
			cap = girl;
		if (cap == root)
			return;
		bic = array[root];
		array[root] = array[cap];
		array[cap] = bic;
		print_array(array, size);
		root = cap;
	}
}

/**
* make_heap - makes a heap from an unsorted array
* @array: array to turn into a heap
* @size: size of the array
*
* Return: void
*/
void make_heap(int *array, size_t size)
{
	size_t mai;

	for (mai = ((size - 1) - 1) / 2; 1; mai--)
	{
		sift_down(array, mai, size - 1, size);
		if (mai == 0)
			break;
	}
}

/**
* heap_sort - sorts an array
* @array: array to sort
* @size: size of the array
*
* Return: void
*/
void heap_sort(int *array, size_t size)
{
	size_t ice;
	int bic;

	if (array == NULL || size < 2)
		return;
	make_heap(array, size);
	ice = size - 1;
	while (ice > 0)
	{
		bic = array[ice];
		array[ice] = array[0];
		array[0] = bic;
		print_array(array, size);
		ice--;
		sift_down(array, 0, ice, size);
	}
}
