#include "lists.h"

/**
 *
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *head, *new;
	head = *h;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	if (head->next == NULL)
		return (add_dnodeint_end(h, n));
	for (; idx != 1; idx--)
	{
		head = head->next;
		if (head == NULL)
			return (NULL);
	}

	new->n = n;
	new->prev = head;
	new->next = head->next;
	head->next->prev = new;
	head->next = new;


	return new;



}
