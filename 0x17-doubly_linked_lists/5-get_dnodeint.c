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
	if (head == NULL)
		return (NULL);
	while (head->prev != NULL)
		head = head->prev;

	for (; index != 0; index--)
		head = head->next;
	return (head);
}
