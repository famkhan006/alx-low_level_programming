#include "lists.h"

/**
 * print_listint_safe - function that prints a linked list with a loop safely.
 * @head: pointer to the 1st node of the linked list
 * Return: number of nodes printed
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tmp = NULL;
	const listint_t *loop = NULL;
	size_t count = 0;
	size_t index;

	tmp = head;
	while (tmp)
	{
		printf("[%p] %d\n", (void *)tmp, tmp->n);
		count++;
		tmp = tmp->next;
		loop = head;
		index = 0;
		while (index < count)
		{
			if (tmp == loop)
			{
				printf("-> [%p] %d\n", (void *)tmp, tmp->n);
				return (count);
			}
			loop = loop->next;
			index++;
		}
		if (!head)
			exit(98);
	}
	return (count);
}
