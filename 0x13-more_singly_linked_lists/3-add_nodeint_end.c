#include "lists.h"

/**
* add_nodeint_end - adds a node at the end of a linked list.
* @head: pointer to the head of linked list.
* @n: number to be added to the new node.
* Return: pointer to the new node/NULL if it fails.
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new;
listint_t *last;

new = malloc(sizeof(listint_t));
if (new == NULL)

return (NULL);
new->n = n;
new->next = NULL;

if (*head == NULL)
*head = new;
else
{
last = *head;
while (last->next != NULL)
last = last->next;
last->next = new;
}

return(*head);
}
