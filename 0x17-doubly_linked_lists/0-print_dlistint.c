#include "lists.h"
/**
 * print_dlistint - counts the number of nodes
 * @h: head pointer to the nodes
 *
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	while (h)
	{
		count++;
		printf("%i\n", h->n);
		h = h->next;
	}
	return (count);
}
