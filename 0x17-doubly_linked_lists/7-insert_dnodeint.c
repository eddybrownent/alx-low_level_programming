#include "lists.h"

/**
 * insert_dnodeint_at_index - adds a node at nth postion
 * @h: pointer t the head of the list
 * @n: the integer in the node
 * @idx: the index at which the node will insert
 *
 * Return: addres of the new node or NULL if fail
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *head, *new;

	head = *h;
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return  (NULL);

	if (idx == 0)
		new =  (add_dnodeint(h, n));

	if (head->next == NULL)
		new =  (add_dnodeint_end(h, n));

	while (head->prev)
		head = head->prev;

	for (; idx != 1; idx--)
	{
		head = head->next;
		if (head == NULL)
			return (NULL);
	}

	new->n = n;
	new->next = head->next;
	new->prev = head;
	head->next->prev = new;
	head->next = new;


	return (new);



}
