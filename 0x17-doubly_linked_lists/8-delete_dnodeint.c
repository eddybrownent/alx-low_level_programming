#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes  node at a given index
 * @head: pointer to head of the list
 * @index: index of node to delete
 *
 *
 * Return: 1 if succeeded, -1 if failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *previous;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	current = *head;
	previous = NULL;

	while (current != NULL && i < index)
	{
		previous = current;
		current = current->next;
		i++;
	}

	if (current == NULL)
		return (-1);

	if (previous == NULL)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}
	else
	{
		previous->next = current->next;
		if (current->next != NULL)
			current->next->prev = previous;
	}

	free(current);
	return (1);
}
