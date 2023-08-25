#include "lists.h"
#include <stdio.h>

/**
 * print_list - Prints all the elements of a list_t limnked list.
 * @h: A pointer to the head of the list_t list.
 *
 * Return: The number of nodes in the list_t list.
 */
size_t print_list(const list_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%i] %s\n", h->len, h->str);
		h = h->next;
		nodes++;
	}

	return (nodes);
}
