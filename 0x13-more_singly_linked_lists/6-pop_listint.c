#include "lists.h"

/**
* pop_listint - deletes the head node of a linked list.
* @head: pointer to the first element in the linked list.
* Return: head node’s data (n),
* if the linked list is empty return 0
*/

int pop_listint(listint_t **head)
{
listint_t *temp;
int numb;

if (*head == NULL)

return (0);

temp = *head;
numb = (*head)->n;
*head = (*head)->next;

free(temp);

return (numb);
}
