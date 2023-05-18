#include "lists.h"

/**
 * add_dnodeint_end - adds new node at end of double linked list
 * @n: the new number to be added
 * @head: points to the list
 *
 * Return: new_node
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_n, *hp;

	new_n = malloc(sizeof(dlistint_t));
	if (new_n == NULL)
		return (NULL);

	new_n->n = n;
	new_n->next = NULL;

	hp = *head;

	if (*head == NULL)
	{
		new_n->prev = NULL;
		*head = new_n;
		return (new_n);
	}

	while (hp->next != NULL)
		hp = hp->next;
	hp->next = new_n;
	new_n->prev = hp;

	return (new_n);
}
