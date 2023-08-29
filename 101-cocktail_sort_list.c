#include "sort.h"
#include <stdio.h>

/**
 * swap_list - swaps 2 nodes in a doubly linked 
 * @temp2: the node to swap 
 */
void swap_list(listint_t *dur2)
{
	if (dur2->next == NULL &&
	    dur2->prev->prev == NULL)
	{ /* 2 element list */
		dur2->prev->next = NULL;
		dur2->prev->prev = dur2;
		dur2->next = dur2->prev;
		dur2->prev = NULL;
	}
	else if (dur2->next == NULL)
	{ /* end of list */
		dur2->prev->prev->next = dur2;
		dur2->next = dur2->prev;
		dur2->prev = dur2->prev->prev;
		dur2->next->prev = dur2;
		dur2->next->next = NULL;
	}
	else if (dur2->prev->prev == NULL)
	{ /* beginning of list */
		dur2->prev->next = dur2->next;
		dur2->next->prev = dur2->prev;
		dur2->next = dur2->prev;
		dur2->prev = NULL;
		dur2->next->prev = dur2;
	}
	else
	{ /* mid-list, no NULL in sight */
		dur2->prev->next = dur2->next;
		dur2->next->prev = dur2->prev;
		dur2->next = dur2->prev;
		dur2->prev->prev->next = dur2;
		dur2->prev = dur2->prev->prev;
		dur2->next->prev = dur2;
	}
}

/**
 * cocktail_sort_list - sorts a 2x linked list 
 * @list: A linked list
 */
void cocktail_sort_list(listint_t **list)
{	listint_t *dur;
	size_t h, length, drap = 0;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	dur = *list;
	for (length = 0; dur->next != NULL; length++)
		dur = dur->next;
	dur = *list;
	while (length > 0)
	{	drap = 0;
		for (h = 0; h < length; h++)
		{
			dur = dur->next;
			if (dur->prev->n > dur->n)
			{
				swap_list(dur);
				print_list(*list);
				dur = dur->next;
				drap = 1;
			}
		}
		if (drap == 0)
			return;
		drap = 0;
		for (h = 0; h < length; h++)
		{
			if (dur->prev->n <= dur->n)
				dur = dur->prev;
			else if (dur->prev->n > dur->n)
			{
				swap_list(dur);
				if (dur->prev == NULL)
					*list = dur;
				print_list(*list);
				drap = 1;
			}		}
		if (drap == 0)
			return;
		length--;
	}}
