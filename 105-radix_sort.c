#include "sort.h"
/**
* pow_10 - calculates a positive power of 10
* @power: power of 10 to calculate
* Return: final result
*/
unsigned int pow_10(unsigned int power)
{
	unsigned int h, mic;

	mic = 1;
	for (h = 0; h < power; h++)
		mic *= 10;
	return (mic);
}

/**
* count_sort - sorts an array of integers
* @array: array of element
* @size: size of the array 
* @digit: digit of element
*
* Return: 1, otherwise 0
*/
unsigned int count_sort(int *array, size_t size, unsigned int digit)
{
	int h, count[10] = {0};
	int *mic = NULL;
	size_t s, bic, result = 0;
	unsigned int dp1, dp2, cat = 0;

	dp2 = pow_10(digit - 1);
	dp1 = dp2 * 10;
	mic = malloc(sizeof(int) * size);
	if (mic == NULL)
		exit(1);
	for (s = 0; s < size; s++)
	{
		mic[s] = array[s];
		if (array[s] / dp1 != 0)
			cat = 1;
	}
	for (h = 0; h < 10 ; h++)
		count[h] = 0;
	for (s = 0; s < size; s++)
		count[(array[s] % dp1) / dp2] += 1;
	for (h = 0; h < 10; h++)
	{
		bic = count[h];
		count[h] = result;
		result += bic;
	}
	for (s = 0; s < size; s++)
	{
		array[count[(mic[s] % dp1) / dp2]] = mic[s];
		count[(mic[s] % dp1) / dp2] += 1;
	}
	free(mic);
	return (cat);
}

/**
* radix_sort - finds radix to be printed
* @array: array 
* @size: size of the array
*/
void radix_sort(int *array, size_t size)
{
	unsigned int h, bic = 1;

	if (array == NULL || size < 2)
		return;
	for (h = 1; bic == 1; h++)
	{
		bic = count_sort(array, size, h);
		print_array(array, size);
	}
}
