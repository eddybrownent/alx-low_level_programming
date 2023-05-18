#include "lists.h"

/**
 * free_dlistint - frees a double linked list
 * @head: points to the list
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
