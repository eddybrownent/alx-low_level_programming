#include "hash_tables.h"

/**
 * hash_table_print - prints the hash table
 * @ht: the hash table tp print
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{"); /* start printing the hash table in curly braces */
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			if (!first)
				printf(", ");/*print comma and space its not the first key-value*/
			printf("'%s': '%s'", node->key, node->value);
			first = 0;
			node = node->next;/*Move to the next node in the linked list*/
		}
	}
	printf("}\n");/* End printing the hash table and print a newline character */
}
