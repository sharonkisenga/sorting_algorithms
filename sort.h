#ifndef __sort__
#define __sort__

#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);

void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);

void swap_int(int *a, int *b);

void insertion_sort_list(listint_t **list);

void swap_list(listint_t *temp2);

void TDSplitMerge(size_t start, size_t end, int *array, int *clone);

void merge_sort(int *array, size_t size);

void selection_sort(int *array, size_t size);

void quick_sort(int *array, size_t size);

void heap_sort(int *array, size_t size);

void radix_sort(int *array, size_t size);

void shell_sort(int *array, size_t size);

void cocktail_sort_list(listint_t **list);

void counting_sort(int *array, size_t size);

#endif /* __sort__ */
