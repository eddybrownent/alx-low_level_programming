#include "lists.h"

/**
 * sum_listint - prints the sum of all numbers in  listint_t list
 * @head: pointer to first node in the linked list
 * Return: sum
 */

int sum_listint(listint_t *head)
{
int sum;

sum = 0;

while (head)
{
sum += head->n;
head = head->next;
}

return (sum);
}
