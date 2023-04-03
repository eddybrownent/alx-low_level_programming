#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node in a linked list
 * @head: pointer to the linked list.
 * @index: index of the node.
 * Return: pointer to the nth node, or NULL.
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int n;

for (n = 0; n < index; n++)
{
if (head == NULL)

return (NULL);
head = head->next;
}
return (head);
}
