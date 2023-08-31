#include "lists.h"

/**
 * add_nodeint_end - adds a node at the end of a linked list
 * @head: pointer to the first element in the list
 * @n: data to insert in the new element
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
<<<<<<< HEAD
	listint_t *curr = *head;
=======

	listint_t *curr = *head;

>>>>>>> 40f6b5ebe51d6931d2e675a7285053bebaa788cc

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

<<<<<<< HEAD
	while (curr->next)
		curr = curr->next;

	curr->next = new;
=======

	while (current->next)
		current = current->next;

	current->next = new;

>>>>>>> 40f6b5ebe51d6931d2e675a7285053bebaa788cc

	return (new);
}
