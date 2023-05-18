#include "lists.h"
/**
 * dlistint_len - counts the elemnts in double linked list
 * @h: the pointer to the list
 *
 * Return: the number of elements
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t eleme = 0;

	while (h != NULL)
	{
		eleme++;
		h = h->next;
	}
	return (eleme);
}
