#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: the hash table to delete
 */

void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node, *temp;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			temp = node->next;/* Store the next node in a temporary variable */
			free(node->key);/* Free the memory allocated for the key */
			free(node->value);/* Free the memory allocated for the value */
			free(node);/* Free the memory allocated for the node */
			node = temp;/* Move to the next node */
		}
	}

	free(ht->array);/* Free the memory allocated for the array */
	free(ht);/* Free the memory allocated for the hash table */
}
