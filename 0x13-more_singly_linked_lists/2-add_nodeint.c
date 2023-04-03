#include "lists.h"

/**
* add_nodeint - adds a new node at the beginning of a linked list.
* @head: pointer to the first node of the list.
* @n: integer to be inserted in the new node.
* Return: pointer to the new node / NULL
*/

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *number;

	number = malloc(sizeof(listint_t));
	if (number != NULL)
	{
		number->n = n;
		number->next = *head;
	}
	else
		return (NULL);
	if (*head != NULL)
		number->next = *head;
	*head = number;
	return (number);
}
