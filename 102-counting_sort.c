#include "sort.h"

/**
* papi_sort - print sort algorithm
* @array: array of the element
* @size: size of the array 
*/
void counting_sort(int *array, size_t size)
{
	int h, manioc;
	int *papi = NULL, *salade = NULL;
	size_t j, temp, total = 0;

	if (array == NULL || size < 2)
		return;
	salade = malloc(sizeof(int) * size);
	if (salade == NULL)
		return;
	for (j = 0, manioc = 0; j < size; j++)
	{
		salade[j] = array[j];
		if (array[j] > manioc)
			manioc = array[j];
	}
	papi = malloc(sizeof(int) * (manioc + 1));
	if (papi == NULL)
	{
		free(salade);
		return;
	}
	for (h = 0; h <= manioc; h++)
		papi[h] = 0;
	for (j = 0; j < size; j++)
		papi[array[j]] += 1;
	for (h = 0; h <= manioc; h++)
	{
		temp = papi[h];
		papi[h] = total;
		total += temp;
	}
	for (j = 0; j < size; j++)
	{
		array[papi[salade[j]]] = salade[j];
		papi[salade[j]] += 1;
	}
	print_array(papi, manioc + 1);
	free(papi);
	free(salade);
}
