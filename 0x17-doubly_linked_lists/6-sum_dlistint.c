#include "lists.h"

/**
 * sum_dlistint - adds all the data of a double linked list
 * @head: points to the linked list head
 *
 * Return: sum of all data
 *
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	if (head == NULL)
		return (0);

	while (head->prev != NULL)
		head = head->prev;


	while (head != NULL)
	{
		sum = sum + head->n;
		head = head->next;
	}

	return (sum);
}

