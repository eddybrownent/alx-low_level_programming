#include "lists.h"
/**
* print_listint - print the eleaments in a linked list.
* @h: head pointer to the linked list.
*
* Return: number of nodes.
*/

size_t print_listint(const listint_t *h)
{
size_t nodes = 0;
while (h != NULL)
{
nodes++;
printf("%i\n", h->n);
h = h->next;
}
return (nodes);
}
