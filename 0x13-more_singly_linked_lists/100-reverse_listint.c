#include "lists.h"

/**
* reverse_listint - reverses a linked list.
* @head: pointer to the linked list.
* Return: pointer to the first node of the list.
*/

listint_t *reverse_listint(listint_t **head)
{
listint_t *n, *pre;

if (head == NULL || *head == NULL)
return (NULL);

pre = NULL;

while ((*head)->next != NULL)
{
n = (*head)->next;
(*head)->next = pre;
pre = *head;
*head = n;
}

(*head)->next = pre;

return (*head);
}
