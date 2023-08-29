#include "sort.h"

/**
 * swap_list - swaps 2 nodes 
 * @dur2: the node 
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
 * insertion_sort_list - sorts 
 * @list: linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *dur2, *dur;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	dur = (*list)->next;
	while (dur != NULL)
	{
		if (dur->prev->n > dur->n)
		{
			dur2 = dur;
			while (dur2 != NULL &&
				 dur2->prev != NULL &&
				 dur2->prev->n > dur2->n)
			{
				swap_list(dur2);
				if (dur2->prev == NULL)
					*list = dur2;
				print_list(*list);
			}
			dur = dur2->next;
		}
		dur = dur->next;
	}
}
