#include "lists.h"
/**
 * get_dnodeint_at_index - returns the nth node of a double linked list
 * @index: the index of the node
 * @head: head of the linked list
 *
 * Return: the node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (head == NULL)
		return (NULL);
	while (head->prev != NULL)
		head = head->prev;

	while (head)
	{
		if (i == index)
			break;
		head = head->next;
		i++;
	}
	return (head);
}
