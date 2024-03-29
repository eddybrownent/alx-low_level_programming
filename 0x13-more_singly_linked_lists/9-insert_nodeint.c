#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list,
 * at a given position
 * @head: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: the number in the new node
 * Return: pointer to the new node, or NULL
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
listint_t *new, *tmp = *head;
unsigned int node;

new = malloc(sizeof(listint_t));

if (new == NULL)
return (NULL);
new->n = n;

if (idx == 0)
{
new->next = tmp;
*head = new;
return (new);
}

for (node = 0; node < (idx - 1); node++)
{
if (tmp == NULL || tmp->next == NULL)
return (NULL);

tmp = tmp->next;
}

new->next = tmp->next;
tmp->next = new;

return (new);
}
